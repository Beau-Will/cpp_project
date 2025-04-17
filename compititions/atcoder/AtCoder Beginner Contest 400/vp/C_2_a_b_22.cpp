#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  i64 num;
  std::cin >> num;

  std::cout << i64(sqrt(num / 2)) + i64(sqrtl(num / 4)) << "\n";
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