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
  int n;
  std::cin >> n;

  for (int i = 30; i >= 1; --i) {
    i64 cur = 0;
    for (int j = 1;; ++j) {
      cur += std::pow(j, i);
      if (cur > n) {
        break;
      }
      if (cur == n) {
        bool flag = false;
        for (int k = 1; k <= j; ++k) {
          if (!flag) {
            std::cout << k << "^" << i;
            flag = true;
          } else {
            std::cout << "+" << k << "^" << i;
          }
        }
        std::cout << "\n";
        return;
      }
    }
  }

  std::cout << "Impossible for " << n << ".\n";
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