#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> dp1(n), dp2(n);
  for (int i = 0; i < n; ++i) {
    dp1[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        dp1[i] = std::max(dp1[i], dp1[j] + 1);
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    dp2[i] = 1;
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[i]) {
        dp2[i] = std::max(dp2[i], dp2[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = std::max(ans, dp1[i] + dp2[i] - 1);
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