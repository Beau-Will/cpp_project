#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> w(n + 1);
  for (int i = 1; i <= n; ++i) {
    int t;
    std::cin >> t;
    w[i].push_back(t);
  }

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool flag = false;
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    if (adj[u].size() == 1) {
      flag = true;
      return;
    }
    for (auto &v : adj[u]) {
      if (v == fa) {
        continue;
      }
      dfs(v, u);
    }

    if (flag) {
      std::vector<int> dp(w[u].back() + 1, -inf);
      dp[0] = 0;
      for (auto &i : adj[u]) {
        for (int j = w[u].back(); j >= 0; --j) {
          for (int k = 0; k < w[i].size(); ++k) {
            if (w[i][k] > j) {
              continue;
            }
            dp[j] = std::max(dp[j], dp[j - w[i][k]] + w[i][k]);
          }
        }
      }

      w[u].clear();
      for (int i = 0; i < dp.size(); ++i) {
        if (dp[i] >= 0) {
          w[u].push_back(dp[i]);
        }
      }
      std::sort(w[u].begin(), w[u].end());
      w[u].erase(std::unique(w[u].begin(), w[u].end()), w[u].end());
    }
  };

  dfs(1, 0);

  int ans = 0;
  for (int i = 0; i < w[1].size(); ++i) {
    ans = std::max(ans, w[1][i]);
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}