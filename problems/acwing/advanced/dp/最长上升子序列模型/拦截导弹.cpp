#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  std::vector<int> a;
  int h;
  while (std::cin >> h) {
    a.push_back(h);
  }
  int n = a.size();

  int ans1 = 0, ans2 = 0;
  std::vector<int> dp1(n), dp2(n);
  for (int i = 0; i < n; ++i) {
    dp1[i] = 1;
    dp2[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (a[j] >= a[i]) {
        dp1[i] = std::max(dp1[i], dp1[j] + 1);
      }
      if (a[j] < a[i]) {
        dp2[i] = std::max(dp2[i], dp2[j] + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans1 = std::max(ans1, dp1[i]);
    ans2 = std::max(ans2, dp2[i]);
  }

  std::cout << ans1 << "\n" << ans2 << "\n";
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