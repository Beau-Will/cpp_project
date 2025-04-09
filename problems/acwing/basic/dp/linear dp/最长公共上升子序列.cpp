#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
  }

  int ans = 0;
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    int max = 1;
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (a[i] == b[j]) {
        dp[i][j] = std::max(dp[i][j], max);
      }
      if (a[i] > b[j]) {
        max = std::max(max, dp[i - 1][j] + 1);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    ans = std::max(ans, dp[n][i]);
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