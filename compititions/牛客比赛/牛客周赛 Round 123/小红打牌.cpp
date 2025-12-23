#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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
  int n;
  std::cin >> n;

  std::vector<int> cnt(200001);
  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;
    ++cnt[x];
  }
  int cnt2 = 0,cnt4 = 0;
  for(int i = 1; i <= 200000; i++){
    cnt2 += cnt[i]>=2;
    cnt4 += cnt[i]>=4;
  }

  Z ans = 0;
  for(int i = 1; i < 200000; i++){
    if(cnt[i]>=3 && cnt[i+1]>=3){
      int c2 = cnt2-2;
      int c4 = cnt4-(cnt[i]>=4)-(cnt[i+1]>=4);
      ans +=  Z(1LL*c2*(c2-1)/2);
      ans += c4;
      if(cnt[i]>=5){
        ans += c2;
      }
      if(cnt[i+1]>=5){
        ans += c2;
      }
      if(cnt[i]>=5 && cnt[i+1]>=5){
        ans += 1;
      }
      if(cnt[i]>=7){
        ans += 1;
      }
      if(cnt[i+1]>=7){
        ans += 1;
      }
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}