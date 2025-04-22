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
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> a(k), b(k);
  for (int i = 0; i < k; ++i) {
    std::cin >> a[i] >> b[i];
  }

  auto dp = std::vector(n + 1, std::vector<int>(m + 1, -inf1));
  dp[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = n; j >= a[i]; --j) {
      for (int l = m - 1; l >= b[i]; --l) {
        dp[j][l] = std::max(dp[j][l], dp[j - a[i]][l - b[i]] + 1);
      }
    }
  }

  int max = -1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m - 1; ++j) {
      max = std::max(max, dp[i][j]);
    }
  }

  int min = m + 1;
  for (int i = 0; i <= m - 1; ++i) {
    for (int j = n; j >= 0; --j) {
      if (dp[j][i] == max) {
        min = std::min(min, i);
      }
    }
  }

  std::cout << max << " " << m - min << "\n";
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