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
  int m, g, n;
  std::cin >> m >> g >> n;

  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i] >> c[i];
  }

  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(g + 1, inf1));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= 0; --j) {
      for (int k = g; k >= 0; --k) {
        dp[j][k] = std::min(
            dp[j][k], dp[std::max(0, j - a[i])][std::max(0, k - b[i])] + c[i]);
      }
    }
  }

  std::cout << dp[m][g] << "\n";
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