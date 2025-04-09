#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  std::string s;
  std::cin >> s;

  int n = s.size();
  std::vector<int> dp(n);
  auto same = [&](char c1, char c2) {
    return c1 == c2 || c1 == '?' || c2 == '?';
  };
  if (1 < n && same(s[0], s[1])) {
    dp[1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (i + 2 < n && same(s[i + 1], s[i + 2])) {
      dp[i + 2] = dp[i] + 1;
    }
    if (i + 1 < n) {
      dp[i + 1] = std::max(dp[i + 1], dp[i]);
    }
  }

  std::cout << dp[n - 1] << "\n";
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