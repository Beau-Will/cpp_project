#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto a = std::vector(n + 1, std::vector<int>(m + 1));
  // 0是可通行的路，1是障碍

  for (int i = 1; i <= n; ++i) {
    int s;
    std::cin >> s;
    for (int j = 0; j < s; ++j) {
      int x;
      std::cin >> x;
      a[i][x] = 1;
    }
  }

  int ans = inf1;
  for (int i = 1; i <= n; ++i) {
    auto dist = std::vector(n + 1, std::vector<int>(m + 1, inf1));
    auto vis = std::vector(n + 1, std::vector<bool>(m + 1));

    int res = inf1;
    auto bfs = [&](int sx, int sy) {
      std::vector<int> dx = {-1, 1, 0, 0};
      std::vector<int> dy = {0, 0, -1, 1};

      std::queue<std::pair<int, int>> q;
      q.push({sx, sy});
      dist[sx][sy] = 0;
      vis[sx][sy] = true;

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (y == m) {
          res = std::min(res, dist[x][y]);
          break;
        }

        for (int i = 0; i < 4; ++i) {
          int u = x + dx[i], v = y + dy[i];
          if (u < 1 || u > n || v < 1 || v > m || vis[u][v] || a[u][v]) {
            continue;
          }
          vis[u][v] = true;
          dist[u][v] = dist[x][y] + 1;
          q.push({u, v});
        }
      }
    };

    bfs(i, 1);

    for (int i = 1; i <= n; ++i) {
      res = std::min(res, dist[i][m]);
    }

    ans = std::min(ans, res);
    if (ans == m - 1) {
      break;
    }
  }

  std::cout << ans + 1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}