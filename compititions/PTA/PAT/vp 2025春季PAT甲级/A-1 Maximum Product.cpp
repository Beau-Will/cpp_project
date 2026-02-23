#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> suf1(n + 2), suf2(n + 2);
  suf1[n + 1] = -inf, suf2[n + 1] = inf;
  for (int i = n; i >= 1; i--) {
    suf1[i] = std::max(suf1[i + 1], a[i]);
    suf2[i] = std::min(suf2[i + 1], a[i]);
  }

  for (int i = 1; i <= n; i++) {
    std::cout << (std::max(a[i] * suf1[i], a[i] * suf2[i])) << " \n"[i == n];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for (int Ti = 0; Ti < T; Ti++) {
    solve();
  }

  return 0;
}