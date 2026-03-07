#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, s;
  std::cin >> n >> m >> s;

  std::vector<std::vector<std::array<i64, 2>>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    i64 w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  std::vector<i64> dp(n + 1);

  auto dfs = [&](auto&& self, int u, int f) -> void {
    if(adj[u].size() == 1 && u != s){
      dp[u] = inf;
    }

    for(const auto& [v, w] : adj[u]){
      if(v == f){
        continue;
      }
      self(self, v, u);
      dp[u] += std::min(dp[v], w);
    }
  };

  dfs(dfs, s, -1);
  std::cout << dp[s] << "\n";

  return 0;
}