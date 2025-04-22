#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  while (std::cin >> n) {
    if (n == 0) {
      break;
    }
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> up(n + 1), down(n + 1);
    int ans = n + 1;

    auto dfs = [&](auto &&self, int u, int sum_up, int sum_down) -> void {
      if (sum_up + sum_down >= ans) {
        return;
      }
      if (u == n + 1) {
        ans = std::min(ans, sum_up + sum_down);
        return;
      }
      int idx1 = 1;
      while (idx1 <= sum_up && a[u] < up[idx1]) {
        ++idx1;
      }
      int tmp1 = up[idx1];
      up[idx1] = a[u];
      if (idx1 > sum_up) {
        self(self, u + 1, sum_up + 1, sum_down);
      } else {
        self(self, u + 1, sum_up, sum_down);
        up[idx1] = tmp1;
      }
      int idx2 = 1;
      while (idx2 <= sum_down && a[u] > down[idx2]) {
        ++idx2;
      }
      int tmp2 = down[idx2];
      down[idx2] = a[u];
      if (idx2 > sum_down) {
        self(self, u + 1, sum_up, sum_down + 1);
      } else {
        self(self, u + 1, sum_up, sum_down);
        down[idx2] = tmp2;
      }
    };

    dfs(dfs, 1, 0, 0);
    std::cout << ans << "\n";
  }
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