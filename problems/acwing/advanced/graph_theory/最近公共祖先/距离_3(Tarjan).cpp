#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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
  int n, q;
  std::cin >> n >> q;

  std::vector<std::vector<std::tuple<int,int>>> adj(n + 1);
  for(int i = 0; i < n - 1; i++){
    int u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  std::vector<std::vector<std::tuple<int, int>>> query(n + 1);
  for(int qi = 0; qi < q; qi++){
    int u, v;
    std::cin >> u >> v;
    if(u ^ v){
      query[u].push_back({v, qi});
      query[v].push_back({u, qi});
    }
  }

  DSU dsu(n + 1);

  std::vector<int> dep(n + 1), dist(n + 1);
  dep[1] = 1;
  std::function<void(int, int)> dfs = [&](int u, int fa){
    for(const auto& [v, w] : adj[u]){
      if(v == fa){
        continue;
      }
      dep[v] = dep[u] + 1;
      dist[v] = dist[u] + w;
      dfs(v, u);
    }
  };

  dfs(1, -1);

  std::vector<int> ans(q);
  std::vector<int> st(n + 1);
  std::function<void(int)> tarjan = [&](int u){
    st[u] = 1;
    for(const auto& [v, w] : adj[u]){
      if(!st[v]){
        tarjan(v);
        dsu.merge(u, v);
      }
    }
    for(const auto& [v, id] : query[u]){
      if(st[v] == 2){
        int fv = dsu.find(v);
        ans[id] = dist[u] + dist[v] - dist[fv] * 2;
      }
    }
    st[u] = 2;
  };

  tarjan(1);

  for(int i = 0; i < q; i++){
    std::cout << ans[i] << "\n";
  }
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