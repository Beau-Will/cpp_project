#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

using Z = MInt<P2>;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> prev(n + 1);
  int last = 0;
  for(int i = 1; i <= n; i++){
    prev[i] = last;
    if(a[i]){
      last = i;
    }
  }

  std::vector<Z> dp(n + 2), pre(n + 2);
  dp[1] = pre[1] = 1;
  for(int i = 1; i <= n; i++){
    int cur = 0;
    int j = i;
    while(j >= 1 && (cur & a[j]) == 0){
      cur |= a[j];
      j = prev[j];
    }
    dp[i + 1] = pre[i] - pre[j];
    pre[i + 1] = pre[i] + dp[i + 1];
  }

  std::cout << dp[n + 1] << "\n";
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