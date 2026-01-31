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

  template<typename U>
  int find_first(U x){
    int l = 1,r = _n;

    auto check1 = [&](int pos){
      return query(pos) >= x;
    };

    while(l<r){
      int mid = (l+r)>>1;
      if(check1(mid)){
        r = mid;
      }else{
        l = mid+1;
      }
    }
    return l;
  }

  template<typename U>
  int find_last(U x){
    int l = 1,r = _n;

    auto check2 = [&](int pos){
      return query(pos) <= x;
    };

    while(l<r){
      int mid = (l+r+1)>>1;
      if(check2(mid)){
        l = mid;
      }else{
        r = mid-1;
      }
    }
    return l;
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

struct Q{
  int k1,k2,id;
  bool operator < (const Q &q) const{
    return k1>q.k1;
  }
};

void solve() {
  //y-x<k1
  //y+x<k2
  int n,q;
  std::cin >> n >> q;

  std::vector<std::pair<int, int>> a(n);
  for(auto &[x,y]:a){
    std::cin >> x >> y;
    int X = y-x,Y = y+x;
    x = X,y = Y;
  }

  std::vector<Q> query(q);
  for(int i = 0; i < q; ++i){
    std::cin >> query[i].k1 >> query[i].k2;
    query[i].id = i;
  }

  std::vector<int> v;
  for(auto &[X,Y]:a){
    v.push_back(X);
    v.push_back(Y);
  }
  for(auto &[k1,k2,id]:query){
    v.push_back(k1);
    v.push_back(k2);
  }

  std::sort(all(v));
  v.erase(std::unique(all(v)),v.end());

  auto find = [&](const int &x){
    return std::lower_bound(all(v),x)-v.begin()+1;
  };

  for(auto &[X,Y]:a){
    X = find(X);
    Y = find(Y);
  }
  for(auto &[k1,k2,_]:query){
    k1 = find(k1);
    k2 = find(k2);
  }

  std::sort(all(a));
  std::sort(all(query));

  BIT bit((n+q)*2+1);

  for(auto &[X,Y]:a){
    bit.modify(Y, 1);
  }

  std::vector<int> ans(q);

  int t = n-1;
  for(auto &[k1,k2,id]:query){
    while(t>=0&&a[t].fi>=k1){
      bit.modify(a[t].se, -1);
      --t;
    }
    ans[id] += bit.query(k2-1);
  }

  for(int i = 0; i < q; ++i){
    std::cout << ans[i] << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}