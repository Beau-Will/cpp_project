#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto a = std::vector(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> a[i][j];
    }
  }

  auto dp = std::vector(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
      }
    }
  }

  std::cout << dp[n][m] << "\n";

  std::vector<std::pair<int, int>> ans;
  int cur = m;
  for (int i = n; i >= 1; --i) {
    for (int k = cur; k >= 0; --k) {
      if (dp[i - 1][cur - k] + a[i][k] == dp[i][cur]) {
        ans.push_back({i, k});
        cur -= k;
        break;
      }
    }
  }

  std::sort(all(ans));
  for (auto &[u, v] : ans) {
    std::cout << u << " " << v << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}