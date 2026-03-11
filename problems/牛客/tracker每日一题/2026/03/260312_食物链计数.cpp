#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  std::vector<int> in(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    in[v]++;
  }

  std::vector<bool> vis(n + 1);
  std::vector<int> dp(n + 1);
  auto dfs = [&](auto&& self, int u, int f) -> void {
    vis[u] = true;
    for(const auto& v : adj[u]){
      if(v == f){
        continue;
      }
      if(!vis[v]){
        self(self, v, u);
      }
      dp[u] += dp[v];
    }
  };

  for(int i = 1; i <= n; i++){
    if(adj[i].size() == 0 && in[i]){
      dp[i] = 1;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(in[i] == 0 && adj[i].size()){
      dfs(dfs, i, -1);
      ans += dp[i];
    }
  }

  std::cout << ans << "\n";

  return 0;
}