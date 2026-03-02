#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 1;

  std::function<int(int, int)> dfs = [&](int u, int fa){
    std::vector<int> dp;
    for(const auto& v : adj[u]){
      if(v == fa){
        continue;
      }
      dp.push_back(dfs(v, u));
    }

    std::sort(dp.begin(), dp.end(), std::greater<>());

    int up = 0;
    if(adj[u].size() >= 4){
      up = dp.front() + 1;
      ans = std::max(ans, dp[0] + dp[1] + 1);
    }else if(adj[u].size() == 3){
      up = 1;
      ans = std::max(ans, dp[0] + 1);
    }
    return up;
  };

  dfs(1, -1);

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}