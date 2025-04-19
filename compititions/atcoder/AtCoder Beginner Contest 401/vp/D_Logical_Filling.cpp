#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(),v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

template<const int T>
struct mod_int{
    const static int _mod = T;
    int _x;

    template<typename P>
    mod_int(P n = P{}):_x(n%_mod){}
    mod_int():_x(0){

    }
    int get_value(){
        return _x;
    }
    friend std::istream &operator >> (std::istream &is,mod_int &t){
        return is >> t._x;
    }
    friend std::ostream &operator << (std::ostream &os,const mod_int &t){
        return os << t._x;
    }
    mod_int operator + (const mod_int &a) const{
        int sum = _x+a._x;
        return mod_int(sum>=_mod?sum-_mod:sum);
    }
    mod_int operator - (const mod_int &a) const{
        int minus = _x-a._x;
        return mod_int(minus>=0?minus:minus+_mod);
    }
    mod_int operator * (const mod_int &a) const{
        i64 mul = 1LL*_x*a._x;
        return mod_int(mul%_mod);
    }
    mod_int operator / (const mod_int &a) const{
        return mod_int(1LL*_x*a.inv()%_mod);
    }
    bool operator == (const mod_int &a) const{
        return _x==a._x;
    }
    bool operator != (const mod_int &a) const{
        return _x!=a._x;
    }
    void operator += (const mod_int &a){
        _x += a._x;
        if(_x>=_mod){
            _x -= _mod;
        }
    }
    void operator -= (const mod_int &a){
        _x -= a._x;
        if(_x<0){
            _x += _mod;
        }
    }
    void operator *= (const mod_int &a){
        _x = 1LL*_x*a._x%_mod;
    }
    void operator /= (const mod_int &a){
        _x = 1LL * _x * a.inv()%_mod;
    }
    friend mod_int operator + (int a,const mod_int &b){
        int sum = a+b._x;
        return mod_int(sum>=_mod?sum-_mod:sum);
    }
    friend mod_int operator - (int a,const mod_int &b){
        int minus = a - b._x;
        return mod_int(minus<0?minus+_mod:minus);
    }
    friend mod_int operator * (int a,const mod_int &b){
        i64 mul = 1LL*a*b._x;
        return mod_int(mul%_mod);
    }
    friend mod_int operator / (int a,const mod_int &b){
        i64 div = 1LL*a*b.inv();
        return mod_int(div%_mod);
    }

    template<typename Q>
    mod_int quick_power(Q n) const{
        mod_int res(1),a(_x);
        for(;n;a = a*a){
            if(n&1){
                res = res*a;
            }
            n >>= 1;
        }
        return res;
    }
    mod_int inv() const{
        return quick_power(_mod-2);
    }
};

using Z = mod_int<P1>;
// using Z = mod_int<P2>;

struct DSU {
  int _n;
  std::vector<int> _fa,_size;
  DSU(){}
  DSU(int n){
      init(n);
  }
  void init(int n) {
      _fa.resize(n);
      std::iota(_fa.begin(),_fa.end(),0);
      _size.assign(n,1);
  }
  int find(int x) {
      if(x!=_fa[x]) {
          _fa[x] = find(_fa[x]);
      }
      return _fa[x];
  }
  bool same(int x,int y) {
      return find(x)==find(y);
  }
  bool merge(int x,int y) {
      int fx = find(x);
      int fy = find(y);
      if(fx!=fy) {
          _size[fx]+=_size[fy];
          _fa[fy] = fx;
          return true;
      }
      return false;
  }
};

struct Comb {
  int n;
  std::vector<Z> _fac;
  std::vector<Z> _invfac;
  std::vector<Z> _inv;
  
  Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
  Comb(int n) : Comb() {
      init(n);
  }
  
  void init(int m) {
      if (m <= n) return;
      _fac.resize(m + 1);
      _invfac.resize(m + 1);
      _inv.resize(m + 1);
      
      for (int i = n + 1; i <= m; i++) {
          _fac[i] = _fac[i - 1] * i;
      }
      _invfac[m] = _fac[m].inv();
      for (int i = m; i > n; i--) {
          _invfac[i - 1] = _invfac[i] * i;
          _inv[i] = _invfac[i] * _fac[i - 1];
      }
      n = m;
  }
  
  Z fac(int m) {
      if (m > n) init(2 * m);
      return _fac[m];
  }
  Z invfac(int m) {
      if (m > n) init(2 * m);
      return _invfac[m];
  }
  Z inv(int m) {
      if (m > n) init(2 * m);
      return _inv[m];
  }
  Z binom(int n, int m) {
      if (n < m || m < 0) return 0;
      return fac(n) * invfac(m) * invfac(n - m);
  }
  Z permu(int n,int m) {
    if (n < m || m < 0) return 0;
    return fac(n)*invfac(n-m);
  }
} comb;

/*

  std::vector<int> inv;

  auto pre_procession = [&](int n){
    constexpr int P = 1e9+7;
    inv.resize(n+1);
    inv[0] = inv[1] = 1;
    for(int i = 2;i<=n;++i){
      inv[i] = i64(P-P/i)*inv[P%i]%P;
    }
  };

*/

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  int cnto = 0;
  for(int i = 0; i < n; ++i){
    if(s[i]=='o'){
      ++cnto;
    }
  }

  std::string t = s;

  for(int i = 0; i < n; ++i){
    if(i>0){
      if(t[i-1]=='o'&&t[i]=='?'){
        t[i] = '.';
      }
    }
    if(i<n-1){
      if(t[i+1]=='o'&&t[i]=='?'){
        t[i] = '.';
      }
    }
  }
  // std::cout << t << "\n";

  std::vector<bool> vis(n);

  int cnt = 0,sum = 0;
  for(int i = 0; i < n; ++i){
    if(t[i]=='?'){
      ++sum;
    }else{
      if(sum%2==0&&sum!=0){
        for(int j = i-sum; j <= i-1; ++j){
          vis[j] = true;
        }
      }
      cnt += (sum+1)/2;
      sum = 0;
    }
  }
  if(sum){
    if(sum%2==0){
      for(int j = n-sum; j <= n-1; ++j){
        vis[j] = true;
      }
    }
    cnt += (sum+1)/2;
    sum = 0;
  }

  // std::cout << "cnto:" << cnto << "\n";
  // std::cout << "cnt:" << cnt << "\n";
  // std::cout << "isok:" << isok << "\n";

  if(cnt==k-cnto){
    // std::cout << "branch\n";
    int tmp = 0;
    std::vector<char> c = {'o','.'};
    for(int i = 0; i < n; ++i){
      if(vis[i]){
        continue;
      }
      if(t[i]=='?'){
        t[i] = c[tmp];
        tmp ^= 1;
      }else{
        tmp = 0;
      }
    }
  }

  std::cout << t << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for(;t--;){
    solve();
  }

  return 0;
}