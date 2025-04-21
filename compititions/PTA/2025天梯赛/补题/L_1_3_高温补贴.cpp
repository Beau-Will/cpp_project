#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int T, S, t;
  std::cin >> T >> S >> t;

  if (T > 35 && S == 1 && t >= 33) {
    std::cout << "Bu Tie\n";
    std::cout << T << "\n";
  } else {
    if (S == 0) {
      if (T <= 35 || t < 33) {
        std::cout << "Shu Shi\n";
        std::cout << t << "\n";
      } else {
        std::cout << "Shi Nei\n";
        std::cout << T << "\n";
      }
    } else {
      std::cout << "Bu Re\n";
      std::cout << t << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}