#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n = 30, sum = 10;
  std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(sum + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < sum; ++j) {
      dp[i][0] += dp[i - 1][j];
    }
    for (int j = 1; j <= sum; ++j) {
      dp[i][j] += dp[i - 1][j - 1];
    }
  }
  i64 ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += dp[i][7];
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