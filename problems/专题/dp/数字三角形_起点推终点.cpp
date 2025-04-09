#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cin >> a[i][j];
    }
  }

  std::vector dp(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (i == 0) {
        dp[i][j] = a[i][j];
      } else if (j == 0) {
        dp[i][j] = dp[i - 1][j] + a[i][j];
      } else if (j == i) {
        dp[i][j] = dp[i - 1][j - 1] + a[i][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
      }
    }
  }

  std::cout << *std::max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
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