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
    return k1 < q.k1;
  }
};

void solve() {
  int n,q;
  std::cin >> n >> q;

  std::vector<std::pair<int,int>> a(n);
  std::vector<int> v;
  for(auto &[x,y]:a){
    std::cin >> x >> y;
    int X = x-y,Y = x+y;
    x = X,y = Y;
    v.push_back(X);
    v.push_back(Y);
  }

  std::vector<Q> query(q);
  for(int i = 0; i < q; ++i){
    std::cin >> query[i].k1 >> query[i].k2;
    query[i].k1 *= -1;
    query[i].id = i;
    v.push_back(query[i].k1);
    v.push_back(query[i].k2);
  }

  std::sort(all(v));

  int idx = 1;
  std::map<int,int> map;
  for(int i = 0; i < v.size(); ++i){
    if(i>0&&v[i]>v[i-1]){
      idx++;
    }
    map[v[i]] = idx;
  }

  for(auto &[X,Y]:a){
    X = map[X];
    Y = map[Y];
  }
  for(auto &[k1,k2,_]:query){
    k1 = map[k1];
    k2 = map[k2];
  }

  BIT bit((n+q)*2+1);

  for(auto &[X,Y]:a){
    bit.modify(Y, 1);
  }

  std::sort(all(a));
  std::sort(all(query));

  std::vector<int> ans(q);
  int i = 0;
  for(auto &[k1,k2,id]:query){
    while(i<n && a[i].fi <= k1){
      bit.modify(a[i].second, -1);
      ++i;
    }
    ans[id] = bit.query(k2-1);
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