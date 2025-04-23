#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, inf));
  for (int i = 1; i <= n; ++i) {
    dp[i][1] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      for (int k = 1; k < i; ++k) {
        dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + a[i] * a[i] - a[k] * a[k]);
      }
    }
  }

  int ans = inf;
  for (int i = 1; i <= n; ++i) {
    ans = std::min(ans, dp[i][m]);
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