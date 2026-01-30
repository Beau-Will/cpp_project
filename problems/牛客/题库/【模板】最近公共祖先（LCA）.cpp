#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,m,rt;
  std::cin >> n >> m >> rt;
  
  std::vector<std::vector<int>> adj(n+1);
  for(int i = 1; i < n; i++){
    int x,y;
    std::cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int log = std::log2(n);

  std::vector f(log + 1, std::vector<int>(n + 1));
  std::vector<int> par(n + 1), dep(n + 1);
  dep[rt] = 1;

  std::function<void(int)> dfs = [&](int u) {
    f[0][u] = par[u];
    for (int i = 1; i <= log; i += 1) {
      f[i][u] = f[i - 1][f[i - 1][u]];
    }
    for (const auto& v : adj[u]) {
      if (v == par[u]) {
        continue;
      }
      par[v] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  };

  dfs(rt);

  auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = log; i >= 0; i -= 1) {
      if (dep[f[i][u]] >= dep[v]) {
        u = f[i][u];
      }
    }
    if (u == v) return u;
    for (int i = log; i >= 0; i -= 1) {
      if (f[i][u] != f[i][v]) {
        u = f[i][u], v = f[i][v];
      }
    };
    return f[0][u];
  };

  for(int mi = 0; mi < m; mi++){
    int u,v;
    std::cin >> u >> v;

    std::cout << lca(u,v) << "\n";
  }
}