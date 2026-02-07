#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T = i64, int L = 62>
struct LinearBasis {
  std::array < T, L + 1 > d{};
  std::vector<T> p;
  int cnt = 0;
  bool has_zero = false;

  LinearBasis() {
    d.fill(0);
  }

  // 插入元素
  bool insert(T x) {
    for (int i = L; i >= 0; --i) {
      if (!(x >> i & 1)) continue;
      if (!d[i]) {
        d[i] = x;
        cnt++;
        return true;
      }
      x ^= d[i];
    }
    has_zero = true;
    return false;
  }

  // 检查 x 是否可以由当前线性基异或得到
  bool check(T x) const {
    for (int i = L; i >= 0; --i) {
      if (x >> i & 1) {
        if (!d[i]) return false;
        x ^= d[i];
      }
    }
    return x == 0;
  }

  // 求最大异或值
  T query_max() const {
    T res = 0;
    for (int i = L; i >= 0; --i) {
      res = std::max(res, res ^ d[i]);
    }
    return res;
  }

  // 求最小异或值
  T query_min() const {
    if (has_zero) return 0;
    for (int i = 0; i <= L; ++i) {
      if (d[i]) return d[i];
    }
    return 0;
  }

  // 重构为最简线性基（改造线性基）
  void rebuild() {
    p.clear();
    for (int i = L; i >= 0; --i) {
      for (int j = i - 1; j >= 0; --j) {
        if (d[i] >> j & 1) d[i] ^= d[j];
      }
    }
    for (int i = 0; i <= L; ++i) {
      if (d[i]) p.push_back(d[i]);
    }
  }

  // 查询第 k 小值
  T query_kth(i64 k) {
    if (has_zero) k--; // 如果能组合出0，0是最小的，k需减1
    if (k == 0) return 0;
    if (k >= (1LL << p.size())) return -1; // 超过最大组合数

    T res = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (k >> i & 1) res ^= p[i];
    }
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

  // std::vector<std::vector<int>> at(31);
  // LinearBasis<int, 30> lb;

  // for(int i = 0; i < n; i++){
  //   lb.insert(b[i]);
  // }

  auto merge = [&](const std::vector<int>& va, const std::vector<int>& vb){
    std::vector<int> res;
    int i = 0, j = 0;
    while(i < va.size() && j < vb.size()){
      if(va[i] < vb[j]){
        res.push_back(va[i]);
        i++;
      }else if(va[i] > vb[j]){
        res.push_back(vb[j]);
        j++;
      }else{
        i++, j++;
      }
    }

    while(i < va.size()){
      res.push_back(va[i]);
      i++;
    }
    while(j < vb.size()){
      res.push_back(vb[j]);
      j++;
    }

    return res;
  };

  int xorsum = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());

  std::vector<int> f(31);
  std::vector<std::vector<int>> at(31);

  for(int i = 0; i < n; i++){
    int x = a[i] ^ b[i];
    std::vector<int> cur = {i};
    for(int j = 29; j >= 0; j--){
      if((x >> j) & 1){
        if(f[j] == 0){
          f[j] = x;
          at[j] = std::move(cur);
          break;
        }else{
          x ^= f[j];
          cur = merge(cur, at[j]);
        }
      }
    }
  }

  std::vector<int> t;
  int x = xorsum;
  bool isok = true;

  for(int j = 29; j >= 0; j--){
    if((x >> j) & 1){
      if(f[j] == 0){
        isok = false;
        break;
      }else{
        x ^= f[j];
        t = merge(t, at[j]);
      }
    }
  }

  if(!isok){
    std::cout << "-1\n";
    return;
  }

  if(x != 0){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> ans = a;
  for(int i = 0; i < t.size(); i++){
    ans[t[i]] = b[t[i]];
  }

  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
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