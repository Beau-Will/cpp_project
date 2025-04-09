#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  auto a = std::vector(n + 1, std::vector<int>(n + 1));

  int x, y, c;
  while (std::cin >> x >> y >> c) {
    if (x == 0 && y == 0 && c == 0) {
      break;
    }
    a[x][y] = c;
  }

  auto dp = std::vector(n * 2 + 1, std::vector(n + 1, std::vector<int>(n + 1)));

  for (int k = 2; k <= n * 2; ++k) {
    for (int i1 = 1; i1 <= n; ++i1) {
      for (int i2 = 1; i2 <= n; ++i2) {
        int j1 = k - i1, j2 = k - i2;
        if (j1 < 1 || j1 > n || j2 < 1 || j2 > n) {
          continue;
        }
        int &x = dp[k][i1][i2];
        int t = a[i1][j1] + a[i2][j2];
        if (i1 == i2) {
          t -= a[i1][j1];
        }
        x = std::max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
        x = std::max(x, dp[k - 1][i1 - 1][i2] + t);
        x = std::max(x, dp[k - 1][i1][i2 - 1] + t);
        x = std::max(x, dp[k - 1][i1][i2] + t);
      }
    }
  }

  std::cout << dp[n * 2][n][n] << "\n";
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