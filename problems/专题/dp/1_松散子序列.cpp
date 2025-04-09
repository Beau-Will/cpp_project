#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  std::string s;
  std::cin >> s;

  std::vector<std::vector<int>> dp(s.size(), std::vector<int>(2));
  dp[0][0] = 0;
  dp[0][1] = s[0] - 'a' + 1;
  for (int i = 1; i < s.size(); ++i) {
    int pi = s[i] - 'a' + 1;
    dp[i][1] = dp[i - 1][0] + pi;
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
  }

  std::cout << std::max(dp[s.size() - 1][0], dp[s.size() - 1][1]) << "\n";
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