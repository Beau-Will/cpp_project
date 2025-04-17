#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n, m;
  std::cin >> n >> m;

  i64 ans = 1;
  i64 cur = n;
  for (int i = 0; i < m; ++i) {
    ans += cur;
    if (ans > inf1) {
      std::cout << "inf\n";
      return;
    }
    cur *= n;
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