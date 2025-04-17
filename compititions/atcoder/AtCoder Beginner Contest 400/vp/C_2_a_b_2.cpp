#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  i64 x;
  std::cin >> x;

  i64 half_x = x / 2;
  i64 quater_x = x / 4;

  i64 t1 = std::sqrt(half_x);
  if (t1 * t1 > half_x) {
    --t1;
  }
  i64 t2 = std::sqrt(quater_x);
  if (t2 * t2 > quater_x) {
    --t2;
  }
  std::cout << t1 + t2 << "\n";
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