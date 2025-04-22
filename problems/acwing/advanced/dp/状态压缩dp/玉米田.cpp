#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

template <const int T> struct mod_int {
  const static int _mod = T;
  int _x;

  template <typename P> mod_int(P n = P{}) : _x(n % _mod) {}
  mod_int() : _x(0) {}
  int get_value() { return _x; }
  friend std::istream &operator>>(std::istream &is, mod_int &t) {
    return is >> t._x;
  }
  friend std::ostream &operator<<(std::ostream &os, const mod_int &t) {
    return os << t._x;
  }
  mod_int operator+(const mod_int &a) const {
    int sum = _x + a._x;
    return mod_int(sum >= _mod ? sum - _mod : sum);
  }
  mod_int operator-(const mod_int &a) const {
    int minus = _x - a._x;
    return mod_int(minus >= 0 ? minus : minus + _mod);
  }
  mod_int operator*(const mod_int &a) const {
    i64 mul = 1LL * _x * a._x;
    return mod_int(mul % _mod);
  }
  mod_int operator/(const mod_int &a) const {
    return mod_int(1LL * _x * a.inv() % _mod);
  }
  bool operator==(const mod_int &a) const { return _x == a._x; }
  bool operator!=(const mod_int &a) const { return _x != a._x; }
  bool operator<(const mod_int &a) const { return _x < a._x; }
  bool operator>(const mod_int &a) const { return _x > a._x; }
  bool operator<=(const mod_int &a) const { return _x <= a._x; }
  bool operator>=(const mod_int &a) const { return _x >= a._x; }
  void operator+=(const mod_int &a) {
    _x += a._x;
    if (_x >= _mod) {
      _x -= _mod;
    }
  }
  void operator-=(const mod_int &a) {
    _x -= a._x;
    if (_x < 0) {
      _x += _mod;
    }
  }
  void operator*=(const mod_int &a) { _x = 1LL * _x * a._x % _mod; }
  void operator/=(const mod_int &a) { _x = 1LL * _x * a.inv() % _mod; }
  friend mod_int operator+(int a, const mod_int &b) {
    int sum = a + b._x;
    return mod_int(sum >= _mod ? sum - _mod : sum);
  }
  friend mod_int operator-(int a, const mod_int &b) {
    int minus = a - b._x;
    return mod_int(minus < 0 ? minus + _mod : minus);
  }
  friend mod_int operator*(int a, const mod_int &b) {
    i64 mul = 1LL * a * b._x;
    return mod_int(mul % _mod);
  }
  friend mod_int operator/(int a, const mod_int &b) {
    i64 div = 1LL * a * b.inv();
    return mod_int(div % _mod);
  }

  template <typename Q> mod_int quick_power(Q n) const {
    mod_int res(1), a(_x);
    for (; n; a = a * a) {
      if (n & 1) {
        res = res * a;
      }
      n >>= 1;
    }
    return res;
  }
  mod_int inv() const { return quick_power(_mod - 2); }
};

// using Z = mod_int<P1>;
// using Z = mod_int<P2>;
using Z = mod_int<100000000>;

void solve() {
  int n,m;
  std::cin >> n >> m;

  auto a = std::vector(n+1,std::vector<int>(m+1));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      std::cin >> a[i][j];
    }
  }

  std::vector<int> b(n+1);
  for(int i = 1; i <= n; ++i){
    int base = 1,s = 0;

    for(int j = m; j >= 1; --j){
      s = s+(base*a[i][j]);
      base *= 2;
    }

    b[i] = s;
  }

  std::vector<std::vector<int>> c(n+1);

  c[0].push_back(0);

  auto check = [&](int x){
    for(int i = 0; i < m-1; ++i){
      if((x>>i&1) && (x>>(i+1)&1)){
        return false;
      }
    }
    return true;
  };

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < (1<<m); ++j){
      if((b[i] | j) != b[i]){
        continue;
      }
      if(check(j)){
        c[i].push_back(j);
      } 
    }
  }
  
  auto dp = std::vector(n+1,std::vector<Z>(1+(1<<m)));

  dp[0][0] = 1;

  for(int i = 1; i <= n; ++i){
    for(auto &ci:c[i-1]){
      for(auto &di:c[i]){
        if(!(ci&di)){
          dp[i][di] += dp[i-1][ci];
        }
      }
    }
  }

  Z ans = 0;
  for(auto &ci:c[n]){
    ans += dp[n][ci];
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}