#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto a = std::vector(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto dp = std::vector(n + m + 1, std::vector(n + 1, std::vector<int>(n + 1)));
  for (int k = 2; k <= n + m; ++k) {
    for (int i1 = std::max(1, k - m); i1 <= n && i1 < k; ++i1) {
      for (int i2 = std::max(1, k - m); i2 <= n && i2 < k; ++i2) {
        int j1 = k - i1, j2 = k - i2;
        if (j1 < 1 || j1 > m || j2 < 1 || j2 > m) {
          continue;
        }
        int &x = dp[k][i1][i2];
        int t = a[i1][j1] + a[i2][j2];
        if (j1 == j2 && k != 2 && k != n + m) {
          continue;
        }
        x = std::max(x, dp[k - 1][i1 - 1][i2] + t);
        x = std::max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
        x = std::max(x, dp[k - 1][i1][i2] + t);
        x = std::max(x, dp[k - 1][i1][i2 - 1] + t);
      }
    }
  }

  std::cout << dp[n + m][n][n];
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