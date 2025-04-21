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

  auto cal = [&](int x) { return (x * (x + 1ll) / 2); };

  std::vector pre(n, std::vector<i64>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pre[i][j] = cal(j) + cal(i);
      if (i && j)
        pre[i][j] += pre[i - 1][j - 1] + 1ll * i * j;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      i64 x;
      std::cin >> x;
      std::cout << x * (pre[i][j] + pre[n - 1 - i][j] + pre[i][m - 1 - j] +
                        pre[n - 1 - i][m - 1 - j] - cal(j) - cal(m - 1 - j) -
                        cal(i) - cal(n - 1 - i))
                << " \n"[j == m - 1];
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