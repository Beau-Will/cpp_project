#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct DSU {
  int _n;
  std::vector<int> _fa, _siz;
  DSU() {}
  DSU(int n) {
    init(n);
  }
  void init(int n) {
    _fa.resize(n);
    std::iota(_fa.begin(), _fa.end(), 0);
    _siz.assign(n, 1);
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
      _siz[fx] += _siz[fy];
      _fa[fy] = fx;
      return true;
    }
    return false;
  }
  int size(int x) {
    return _siz[find(x)];
  }
};

void solve(){
  int n, m, x, d;
  std::cin >> n >> m >> x >> d;

  std::vector<int> h(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> h[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> H(x + 1);
  for(int i = 1; i <= x; i++){
    std::cin >> H[i];
  }

  std::vector<std::tuple<int, int>> v;
  for(int i = 1; i <= n; i++){
    v.push_back({h[i], i});
  }

  std::sort(v.begin(), v.end());

  std::vector<bool> vis(n + 1);
  std::vector<int> ans(x + 1);
  int cnt = 0, idx = n - 1;
  DSU dsu(n + 1);

  for(int i = x; i >= 1; i--){
    while(idx >= 0 && std::get<0>(v[idx]) > H[i]){
      int u = std::get<1>(v[idx]);
      vis[u] = true;
      if(d == 1){
        cnt++;
      }

      for(const auto& v : adj[u]){
        if(vis[v] && !dsu.same(u, v)){
          if(dsu.size(u) >= d){
            cnt--;
          }
          if(dsu.size(v) >= d){
            cnt--;
          }

          dsu.merge(u, v);
          if(dsu.size(u) >= d){
            cnt++;
          }
        }
      }

      idx--;
    }

    ans[i] = cnt;
  }

  for(int i = 1; i <= x; i++){
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