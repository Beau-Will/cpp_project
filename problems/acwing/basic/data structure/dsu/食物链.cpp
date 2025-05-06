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

struct DSU {
  int _n;
  std::vector<int> _fa,_size,_dist;
  
  DSU(int n = 0){
      init(n);
  }

  void init(int n) {
    _n = n;
    _fa.resize(_n);
    std::iota(_fa.begin(),_fa.end(),0);
    _size.assign(_n,1);
    _dist.assign(_n,0);
  }

  int find(int x) {
    if(x!=_fa[x]) {
      int t = find(_fa[x]);
      _dist[x] += _dist[_fa[x]];
      _fa[x] = t;
    }
    return _fa[x];
  }

  bool same(int x,int y) {
    return find(x)==find(y);
  }

  bool merge(int x,int y) {
    int fx = find(x);
    int fy = find(y);

    if(fx != fy) {
      if(_size[fx] > _size[fy]){
        _size[fx] += _size[fy];
        _fa[fy] = fx;
      }else{
        _size[fy] += _size[fx];
        _fa[fx] = fy;
      }

      return true;
    }
    return false;
  }
};

void solve() {
  int n,m;
  std::cin >> n >> m;

  DSU dsu(n+1);

  int ans = 0;

  for(;m--;){
    int t,u,v;
    std::cin >> t >> u >> v;

    if(u>n || v>n){
      ++ans;
    }else{
      int fu = dsu.find(u),fv = dsu.find(v);
      if(t==1){
        if(fu==fv){
          if((dsu._dist[u]-dsu._dist[v])%3){
            ++ans;
          }
        }else{
          dsu._fa[fu] = fv;
          dsu._dist[fu] = dsu._dist[v]-dsu._dist[u];
        }
      }else{
        if(fu==fv){
          if((dsu._dist[u]-dsu._dist[v]-1)%3){
            ++ans;
          }
        }else{
          dsu._fa[fu] = fv;
          dsu._dist[fu] = dsu._dist[v]+1-dsu._dist[u];
        }
      }
    }
  }

  std::cout << ans << "\n";
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