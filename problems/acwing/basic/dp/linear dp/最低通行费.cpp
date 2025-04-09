#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  auto a = std::vector(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto dp = std::vector(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        dp[i][j] = a[i][j];
      } else if (i == 0) {
        dp[i][j] = dp[i][j - 1] + a[i][j];
      } else if (j == 0) {
        dp[i][j] = dp[i - 1][j] + a[i][j];
      } else {
        dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
      }
    }
  }

  std::cout << dp[n - 1][n - 1] << "\n";
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