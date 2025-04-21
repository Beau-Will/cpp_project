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
  int n, m, q;
  std::cin >> n >> m >> q;

  auto a = std::vector(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> a[i][j];
    }
  }

  using Node = std::tuple<int, int, int>;

  std::priority_queue<Node> pq;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pq.push({a[i][j], i, j});
    }
  }

  std::vector<bool> row(n + 1), col(m + 1);

  for (; q--;) {
    auto [max, x, y] = pq.top();
    pq.pop();

    row[x] = true;
    col[y] = true;

    auto [_1, x2, y2] = pq.top();
    while (pq.size() && (row[x2] || col[y2])) {
      pq.pop();
      auto [_2, x3, y3] = pq.top();
      x2 = x3;
      y2 = y3;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (row[i]) {
      continue;
    }
    bool flag = false;
    for (int j = 1; j <= m; ++j) {
      if (col[j]) {
        continue;
      }
      if (!flag) {
        std::cout << a[i][j];
        flag = true;
      } else {
        std::cout << " " << a[i][j];
      }
    }
    if (flag)
      std::cout << "\n";
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