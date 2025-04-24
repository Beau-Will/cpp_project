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

using BIT = Fenwick<int>;
// using BIT = Fenwick<i64>;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> tr(n+1);
  std::vector<int> lower(n+1),upper(n+1);

  BIT bit;

  for(int i = 1; i <= n; ++i){
    lower[i] = bit.query(a[i]-1);
    upper[i] = bit.range_query(a[i]+1,n);
    bit.modify(a[i],1);
  }

  bit.assign(n);

  i64 ans1 = 0,ans2 = 0;
  for(int i = n; i >= 1; --i){
    ans1 += 1LL*upper[i]*bit.range_query(a[i]+1,n);
    ans2 += 1LL*lower[i]*bit.query(a[i]-1);
    bit.modify(a[i],1);
  }

  std::cout << ans1 << " " << ans2 << "\n";
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