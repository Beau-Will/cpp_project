#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int ans = 0;
  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = a[i];
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        dp[i] = std::max(dp[i], dp[j] + a[i]);
      }
    }
    ans = std::max(ans, dp[i]);
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