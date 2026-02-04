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
  int n;
  std::cin >> n;

  std::vector<int> all;
  std::vector<std::pair<int, int>> edges;
  int rt = -1;
  for(int i = 0; i < n; i++){
    int u, v;
    std::cin >> u >> v;
    if(~v){
      edges.push_back({u, v});
      all.push_back(u);
      all.push_back(v);
    }else{
      rt = u;
      all.push_back(u);
    }
  }

  std::sort(all.begin(), all.end());
  all.erase(std::unique(all.begin(), all.end()), all.end());

  auto query = [&](int x){
    return std::lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };

  rt = query(rt);

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < n - 1; i++){
    auto [u, v] = edges[i];
    u = query(u);
    v = query(v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int m;
  std::cin >> m;

  std::vector<std::vector<std::pair<int, int>>> q(n + 1);
  std::vector<std::pair<int, int>> querys(m);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;
    u = query(u);
    v = query(v);
    querys[i] = {u, v};

    q[u].push_back({v, i});
    q[v].push_back({u, i});
  }

  std::vector<int> dep(n + 1);
  dep[rt] = 1;
  std::function<void(int, int)> dfs = [&](int u, int fa){
    for(const auto& v : adj[u]){
      if(v == fa){
        continue;
      }
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  };

  dfs(rt, -1);

  std::vector<int> ans(m);
  std::vector<int> st(n + 1);
  DSU dsu(n + 1);

  std::function<void(int)> tarjan = [&](int u){
    st[u] = 1;
    for(const auto& v : adj[u]){
      if(!st[v]){
        tarjan(v);
        dsu.merge(u, v);
      }
    }
    for(const auto& [v, id] : q[u]){
      if(st[v] == 2){
        int fv = dsu.find(v);
        ans[id] = fv;
      }
    }
    st[u] = 2;
  };

  tarjan(rt);

  for(int i = 0; i < m; i++){
    auto [u, v] = querys[i];
    if(ans[i] == u){
      std::cout << "1\n";
    }else if(ans[i] == v){
      std::cout << "2\n";
    }else{
      std::cout << "0\n";
    }
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