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

  std::vector<int> dp(m + 1);
  for (int i = 0; i < n; ++i) {
    int u, v, s;
    std::cin >> u >> v >> s;
    if (s == 0) {
      for (int j = u; j <= m; ++j) {
        dp[j] = std::max(dp[j], dp[j - u] + v);
      }
    } else {
      if (s == -1) {
        s = 1;
      }
      for (int t = 1; t <= s; s -= t, t *= 2) {
        for (int j = m; j >= u * t; --j) {
          dp[j] = std::max(dp[j], dp[j - u * t] + v * t);
        }
      }
      if (s) {
        for (int j = m; j >= u * s; --j) {
          dp[j] = std::max(dp[j], dp[j - u * s] + v * s);
        }
      }
    }
  }

  std::cout << dp[m] << "\n";
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