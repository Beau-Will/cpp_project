#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());

  std::set<int> set;
  for (int i = 0; i < n / 2; i++) {
    set.insert(a[i] + a[n - 1 - i]);
  }

  std::cout << (*set.rbegin() - *set.begin()) << "\n";
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