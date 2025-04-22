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
  int m, n;
  std::cin >> m >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> dp(m + 1, -inf1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= a[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - a[i]] + 1);
    }
  }

  int max;

  for (int i = m; i >= 0; --i) {
    if (dp[i] >= 0) {
      max = i;
      break;
    }
  }

  std::cout << m - max << "\n";
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