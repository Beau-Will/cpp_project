#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

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
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
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
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
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
 
constexpr int P = 100000000;
using Z = MInt<P>;

void solve(){
  int n,m;
  std::cin >> n >> m;

  auto a = std::vector(n+1,std::vector<int>(m));
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < m; j++){
      std::cin >> a[i][j];
    }
  }

  auto check1 = [&](int x){
    for(int i = 0; i < m; i++){
      if((x>>i&1) && (x>>(i+1)&1)){
        return false;
      }
    }
    return true;
  };

  auto check2 = [&](int x,int row){
    for(int i = 0; i < m; i++){
      if((x>>i&1) > a[row][i]){
        return false;
      }
    }
    return true;
  };

  auto st = std::vector(n+2,std::vector<int>());
  
  st[0].push_back(0);
  st[n+1].push_back(0);
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < (1<<m); j++){
      if(check1(j) && check2(j,i)){
        st[i].push_back(j);
      }
    }
  }

  auto dp = std::vector(n+2,std::vector<Z>(1<<m,0));
  dp[0][0] = 1;

  for(int i = 1; i <= n+1; i++){
    for(int j = 0; j < st[i].size(); j++){
      int x = st[i][j];
      for(int k = 0; k < st[i-1].size(); k++){
        int y = st[i-1][k];
        
        if(x & y){
          continue;
        }

        dp[i][x] += dp[i-1][y];
      }
    }
  }

  std::cout << dp[n+1][0] << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}