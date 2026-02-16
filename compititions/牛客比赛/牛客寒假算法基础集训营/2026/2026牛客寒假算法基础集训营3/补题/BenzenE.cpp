#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T = int, int L = 30>
struct LinearBasis {
  std::vector<T> f;                   // 基向量
  std::vector<std::vector<int>> comb; // 每个基向量对应的原始下标集合（有序）
  std::vector<T> p;                   // 重构后的最简基（仅用于第k小）
  int cnt = 0;
  bool has_zero = false;

  LinearBasis() {
    f.resize(L + 1);
    comb.resize(L + 1);
  }

  // 插入元素，必须提供其在原数组中的下标 idx (idx >= 0)
  bool insert(T x, int idx) {
    assert(idx >= 0);                 // 确保下标有效
    std::vector<int> cur = {idx};      // 当前元素对应的下标集合
    for (int i = L; i >= 0; --i) {
      if (!(x >> i & 1)) continue;
      if (!f[i]) {
        f[i] = x;
        comb[i] = std::move(cur);
        cnt++;
        return true;
      }
      x ^= f[i];
      cur = merge(cur, comb[i]);
    }
    has_zero = true;
    return false;                      // 线性相关，未插入新基
  }

  // 检查 x 是否可以由当前线性基异或得到（不输出方案）
  bool check(T x) const {
    for (int i = L; i >= 0; --i) {
      if (x >> i & 1) {
        if (!f[i]) return false;
        x ^= f[i];
      }
    }
    return x == 0;
  }

  // 求最大异或值
  T query_max() const {
    T res = 0;
    for (int i = L; i >= 0; --i) {
      res = std::max(res, res ^ f[i]);
    }
    return res;
  }

  // 求最小异或值
  T query_min() const {
    if (has_zero) return 0;
    for (int i = 0; i <= L; ++i) {
      if (f[i]) return f[i];
    }
    return 0;
  }

  // 重构为最简线性基（同时更新组合信息）
  void rebuild() {
    for (int i = L; i >= 0; --i) {
      if (!f[i]) continue;
      for (int j = i - 1; j >= 0; --j) {
        if ((f[i] >> j) & 1) {
          f[i] ^= f[j];
          comb[i] = merge(comb[i], comb[j]);
        }
      }
    }
    p.resize(L + 1);
    for (int i = 0; i <= L; ++i) {
      if (f[i]) p.push_back(f[i]);
    }
  }

  // 查询第 k 小值（需要先调用 rebuild）
  T query_kth(i64 k) {
    if (has_zero) k--;                 // 0 是最小的
    if (k == 0) return 0;
    if (k >= (1LL << p.size())) return -1;
    T res = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (k >> i & 1) res ^= p[i];
    }
    return res;
  }

  // 查询构造 x 所需的下标集合，若无法构造则返回空 vector
  std::vector<int> query_idx(T x) const {
    if (!check(x)) return {};          // 无法构造
    if (x == 0) return {};             // 0 由空集构造
    std::vector<int> cur;
    T y = x;
    for (int i = L; i >= 0; --i) {
      if ((y >> i) & 1) {
        y ^= f[i];
        cur = merge(cur, comb[i]);
      }
    }
    return cur;
  }

  // 合并两个有序下标集合，返回它们的对称差（仍有序）
  static std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> res;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i] < b[j]) {
        res.push_back(a[i++]);
      } else if (a[i] > b[j]) {
        res.push_back(b[j++]);
      } else {
        ++i;
        ++j;
      }
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    return res;
  }
};

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  int sum = std::accumulate(a.begin(), a.end(), 0, std::bit_xor());
  
  LinearBasis lb;
  for(int i = 0; i < n; i++){
    lb.insert(a[i] ^ b[i], i);
  }

  if(!lb.check(sum)){
    std::cout << "-1\n";
    return;
  }

  auto idx = lb.query_idx(sum);
  std::vector<int> ans = a;
  for(int i = 0; i < idx.size(); i++){
    ans[idx[i]] = b[idx[i]];
  }

  for(int i = 0; i < n; i++){
    std::cout << ans[i] << " \n"[i + 1 == n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}