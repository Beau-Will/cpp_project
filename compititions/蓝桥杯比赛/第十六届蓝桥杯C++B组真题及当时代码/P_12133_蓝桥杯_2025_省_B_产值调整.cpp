#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int a, b, c, k;
  std::cin >> a >> b >> c >> k;

  for (int i = 1; i <= std::min(100, k); ++i) {
    int tmpa = (b + c) / 2;
    int tmpb = (a + c) / 2;
    int tmpc = (a + b) / 2;

    a = tmpa;
    b = tmpb;
    c = tmpc;
  }

  std::cout << a << " " << b << " " << c << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}