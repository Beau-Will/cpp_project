#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

template<typename T>
struct Fenwick{
  int _n;
  std::vector<T> tr;

  void init(int n,T x = {}){
    _n = n;
    tr.assign(_n+1,x);
  }

  Fenwick(int n = 200000,T x = {}){
    init(n,x);
  }

  int lowbit(int x){
    return x&(-x);
  }

  template<typename U>
  void modify(int pos,U x){
    for(int i = pos; i <= _n; i += lowbit(i)){
      tr[i] += x;
    }
  }

  T query(int pos){
    T res {};
    for(int i = pos; i >= 1; i-=lowbit(i)){
      res += tr[i];
    }
    return res;
  }

  T range_query(int l,int r){
    return query(r)-query(l-1);
  }

  void resize(int n){
    init(n);
  }

  void assign(int n,T x = {}){
    init(n,x);
  }

  void clear(){
    _n = 0;
    tr.clear();
  }
};

// using BIT = Fenwick<int>;
using BIT = Fenwick<i64>;

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  BIT bit1(n+1),bit2(n+1);
  for(int i = 1; i <= n; ++i){
    int bi = a[i]-a[i-1];
    bit1.modify(i,bi);
    bit2.modify(i,1LL*i*bi);
  }

  for(;m--;){
    std::string op;
    int l,r;
    std::cin >> op >> l >> r;

    if(op=="Q"){
      i64 sumr = bit1.query(r)*(r+1)-bit2.query(r);
      i64 suml = bit1.query(l-1)*l-bit2.query(l-1);

      std::cout << sumr - suml << "\n";
    }else{
      int x;
      std::cin >> x;

      bit1.modify(l,x);
      bit1.modify(r+1,-x);
      bit2.modify(l,1LL*l*x);
      bit2.modify(r+1,-1LL*(r+1)*x);
    }
  }
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