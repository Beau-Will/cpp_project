#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <array>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  
  std::vector<std::vector<std::array<int, 2>>> adj(n+1);
  for(int i = 0; i < n - 1; i++){
    int u, v, w;
    std::cin >> u >> v >> w;
    
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  
  int log = std::log2(n);

  std::vector f(log + 1, std::vector<int>(n + 1));
  std::vector<int> par(n + 1), dep(n + 1), dist(n + 1);
  dep[1] = 1;
  
  std::function<void(int)> dfs = [&](int u) {
  	f[0][u] = par[u];
  	for (int i = 1; i <= log; i += 1) {
  		f[i][u] = f[i - 1][f[i - 1][u]];
  	}
  	for (const auto& [v, w] : adj[u]) {
  		if (v == par[u]) {
  			continue;
  		}
  		par[v] = u;
  		dep[v] = dep[u] + 1;
  		dist[v] = dist[u] + w;
  		dfs(v);
  	}
  };
  
  dfs(1);

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
    int u, v;
    std::cin >> u >> v;
    
    std::cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << "\n";
  }
}