#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/**
 *    自动取模类
 *    一般定义模数为P
 *    P必须为质数，否则不满足费马小定理，在处理逆元时会出错
**/
template<class T>
constexpr T power(T a, i64 b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

template<int P>
struct MInt {
  int x;
  constexpr MInt() : x{} {}
  constexpr MInt(i64 x) : x{norm(x % getMod())} {}

  static int Mod;
  constexpr static int getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(int Mod_) {
    Mod = Mod_;
  }
  constexpr int norm(int x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr int val() const {
    return x;
  }
  explicit constexpr operator int() const {
    return x;
  }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MInt inv() const {
    assert(x != 0);
    return power(*this, getMod() - 2);
  }
  constexpr MInt& operator*=(MInt rhs)& {
    x = 1LL * x * rhs.x % getMod();
    return *this;
  }
  constexpr MInt& operator+=(MInt rhs)& {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MInt& operator-=(MInt rhs)& {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MInt& operator/=(MInt rhs)& {
    return *this *= rhs.inv();
  }
  friend constexpr MInt operator*(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MInt operator+(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MInt operator-(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MInt operator/(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
    i64 v;
    is >> v;
    a = MInt(v);
    return is;
  }
  friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MInt lhs, MInt rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MInt lhs, MInt rhs) {
    return lhs.val() != rhs.val();
  }
};

/**
 *    模板全特化
 *    使用动态模数（运行时确定）
 *    using Z2 = MInt<0>;       // 模数在运行时设置
 *    Z2::setMod(1000000007);   // 重新设置模数为1000000007
**/
template<>
int MInt<0>::Mod = 998244353;

/**
 *    用于编译期就计算好逆元，可以用于不同的模数
 *    如求2在模数1000000007下的逆元
 *    constexpr auto inv2 = CInv<2, 1000000007>;
**/
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

using Z = MInt<P2>;

struct DSU {
  int _n;
  std::vector<int> _fa, _size;
  DSU() {}
  DSU(int n) {
    init(n);
  }
  void init(int n) {
    _fa.resize(n);
    std::iota(_fa.begin(), _fa.end(), 0);
    _size.assign(n, 1);
  }
  int find(int x) {
    if (x != _fa[x]) {
      _fa[x] = find(_fa[x]);
    }
    return _fa[x];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      _size[fx] += _size[fy];
      _fa[fy] = fx;
      return true;
    }
    return false;
  }
};

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::array<int, 3>> a(m);
  for(int i = 0; i < m; i++){
    auto& [l, r, k] = a[i];
    std::cin >> l >> r >> k;
  }

  std::sort(a.begin(), a.end(), [&](const auto& t1, const auto& t2){
    return t1[2] < t2[2];
  });

  DSU dsu(n + 2);

  std::vector<int> limit(n + 1, n);
  std::vector<bool> is(n + 1);
  std::vector<int> left(n + 1, 1), right(n + 1, n);

  for(int i = 0; i < m; i++){
    auto [l, r, k] = a[i];
    for(int i = dsu.find(l); i <= r; i = dsu.find(i)){
      dsu._fa[i] = dsu.find(i + 1);
      limit[i] = k;
    }
    is[k] = true;
    left[k] = std::max(left[k], l);
    right[k] = std::min(right[k], r);
  }

  std::vector g(n + 1, std::vector<int>());
  for(int i = 1; i <= n; i++){
    g[limit[i]].push_back(i);
  }

  Z ans = 1;
  int siz = 0;

  for(int i = n; i >= 1; i--){
    int have = g[i].size();

    if(is[i]){
      if(left[i] > right[i]){
        std::cout << "0\n";
        return;
      }
      int cnt = 0;
      for(const auto& idx : g[i]){
        if(left[i] <= idx && idx <= right[i]){
          cnt++;
        }
      }
      if(!cnt){
        std::cout << "0\n";
        return;
      }
      ans *= cnt;
      siz += (have - 1);
    }else{
      siz += have;
      if(siz <= 0){
        std::cout << "0\n";
        return;
      }
      ans *= siz;
      siz--;
    }
  }

  std::cout << ans << "\n";
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