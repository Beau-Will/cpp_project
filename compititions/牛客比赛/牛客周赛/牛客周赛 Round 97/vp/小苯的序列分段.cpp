#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

template <const int T> 
struct mod_int {
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

  template <typename Q> 
  mod_int quick_power(Q n) const {
    mod_int res(1), a(_x);
    for (; n; a = a * a) {
      if (n & 1) {
        res = res * a;
      }
      n >>= 1;
    }
    return res;
  }
  mod_int inv() const { 
    return quick_power(_mod - 2);//_mod必须为质数，否则只能用exgcd求inv
  }
};

// using Z = mod_int<P1>;
using Z = mod_int<P2>;

void solve() {
  int n,m;
  std::cin >> n >> m;
  
  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> b(m+1);
  for(int i = 1; i <= m; ++i){
    std::cin >> b[i];
  }

  std::vector<int> stk;
  std::vector<int> R(n+1,n+1);
  for(int i = n; i >= 1; --i){
    while(stk.size()&&a[stk.back()]<a[i]){
      stk.pop_back();
    }
    if(stk.size()){
      R[i] = stk.back();
    }
    stk.push_back(i);
  }

  stk.clear();
  
  std::vector<int> L(n+1);
  for(int i = 1; i <= n; ++i){
    while(stk.size()&&a[stk.back()]<a[i]){
      stk.pop_back();
    }
    if(stk.size()){
      L[i] = stk.back();
    }
    stk.push_back(i);
  }

  std::vector<int> mp(n+1);
  for(int i = 1; i <= n; ++i){
    mp[a[i]] = i;
  }

  for(int i = 1; i <= m; ++i){
    b[i] = mp[b[i]];
  }

  if(L[b[1]]>0 || R[b[m]]<=n){
    std::cout << "0\n";
    return;
  }

  Z ans = 1;

  for(int i = 1; i < m; ++i){
    int l = std::max(b[i],L[b[i+1]]);
    int r = std::min(R[b[i]],b[i+1])-1;
    ans *= std::max(0,r-l+1);
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}