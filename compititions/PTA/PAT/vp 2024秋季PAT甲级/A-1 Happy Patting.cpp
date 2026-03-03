#include <bits/stdc++.h>

constexpr std::array dx = {0, -1, 1, 0, 0};
constexpr std::array dy = {0, 0, 0, -1, 1};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector g(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> g[i][j];
    }
  }

  std::vector cnt(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int u = i + dx[g[i][j]], v = j + dy[g[i][j]];
      if (u < 0 || u >= n || v < 0 || v >= m) {
        continue;
      }
      cnt[u][v]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cnt[i][j] > 1) {
        ans++;
      }
    }
  }

  std::cout << ans << "\n";

  return 0;
}