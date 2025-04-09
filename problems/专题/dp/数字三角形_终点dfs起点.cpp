#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  auto a = std::vector(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cin >> a[i][j];
    }
  }

  constexpr int inf = 1000000000;

  auto dp = std::vector(n, std::vector<int>(n, -inf));

  auto dfs = [&](auto &&self, int i, int j) -> int {
    if (j < 0 || j > i) {
      return -inf;
    }
    if (i == 0) {
      return a[i][j];
    }
    if (dp[i][j] != -inf) {
      return dp[i][j];
    }
    return dp[i][j] = std::max(self(self, i - 1, j - 1), self(self, i - 1, j)) +
                      a[i][j];
  };

  int ans = -inf;
  for (int i = 0; i < n; ++i) {
    ans = std::max(ans, dfs(dfs, n - 1, i));
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