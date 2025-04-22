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
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int v, w, s;
    std::cin >> v >> w >> s;
    int t = 1;
    while (t <= s) {
      a.push_back(v * t);
      b.push_back(w * t);
      s -= t;
      t *= 2;
    }
    if (s) {
      a.push_back(v * s);
      b.push_back(w * s);
      s = 0;
    }
  }

  std::vector<int> dp(m + 1);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = m; j >= a[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - a[i]] + b[i]);
    }
  }

  std::cout << dp[m] << "\n";
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