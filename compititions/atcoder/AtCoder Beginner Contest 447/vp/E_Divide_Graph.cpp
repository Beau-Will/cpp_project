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

constexpr int P = P2;
using Z = MInt<P>;

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

  std::vector<int> u(m), v(m);
  std::vector<Z> cost(m);
  for(int i = 0; i < m; i++){
    std::cin >> u[i] >> v[i];
    cost[i] = power(Z(2), i + 1);
  }

  DSU dsu(n + 1);
  Z ans = 0;
  int cnt = n;

  for(int i = m - 1; i >= 0; i--){
    if(!dsu.same(u[i], v[i])){
      if(cnt > 2){
        dsu.merge(u[i], v[i]);
        cnt--;
      }else{
        ans += cost[i];
      }
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}