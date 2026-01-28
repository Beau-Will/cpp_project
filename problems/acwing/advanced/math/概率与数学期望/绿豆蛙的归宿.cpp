#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});
  }

  std::vector<double> dp(n + 1, -1);

  auto dfs = [&](auto &&self, int u) -> double {
    if (dp[u] >= 0) {
      return dp[u];
    }
    dp[u] = 0;
    for (auto &[v, w] : adj[u]) {
      dp[u] += (w + self(self, v)) / adj[u].size();
    }
    return dp[u];
  };

  dfs(dfs, 1);

  std::cout << std::fixed << std::setprecision(2) << dp[1] << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}