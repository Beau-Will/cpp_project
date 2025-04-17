#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

struct Node {
  int w, x, y;
  bool operator<(const Node &t) const {
    if (w != t.w)
      return w > t.w;
    if (x != t.x)
      return x > t.x;
    return y > t.y;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  auto a = std::vector(n + 1, std::vector<char>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> a[i][j];
    }
  }
  int sx, sy, ex, ey;
  std::cin >> sx >> sy >> ex >> ey;

  auto dist = std::vector(n + 1, std::vector<int>(m + 1, inf1));
  auto vis = std::vector(n + 1, std::vector<bool>(m + 1));
  auto bfs = [&]() {
    std::vector<int> dx1 = {-1, 1, 0, 0};
    std::vector<int> dy1 = {0, 0, -1, 1};
    std::vector<int> dx2 = {-2, 2, 0, 0};
    std::vector<int> dy2 = {0, 0, -2, 2};
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < dx1.size(); ++i) {
        int u = x + dx1[i], v = y + dy1[i];
        if (u < 1 || u > n || v < 1 || v > m || vis[u][v] || a[u][v] == '#') {
          continue;
        }
        vis[u][v] = true;
        dist[u][v] = 0;
        q.push({u, v});
      }
    }

    std::priority_queue<Node> pq;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (dist[i][j] == 0) {
          pq.push({0, i, j});
        }
      }
    }
    while (!pq.empty()) {
      auto [w, x, y] = pq.top();
      std::cout << w << " " << x << " " << y << "\n";
      pq.pop();
      // if (x == ex && y == ey) {
      //   std::cout << w << "\n";
      //   return;
      // }
      for (int i = 0; i < dx1.size(); ++i) {
        int u = x + dx1[i], v = y + dy1[i];
        if (u < 1 || u > n || v < 1 || v > m) { // || vis[u][v]) {
          continue;
        }
        if (x == 7 && y == 2) {
          std::cout << u << " " << v << "\n";
        }
        vis[u][v] = true;
        if (a[u][v] == '.') {
          dist[u][v] = std::min(dist[u][v], w);
        } else {
          dist[u][v] = std::min(dist[u][v], w + 1);
          a[u][v] = '.';
        }
        std::cout << dist[u][v] << "\n";
        pq.push({dist[u][v], u, v});
      }
      for (int i = 0; i < dx2.size(); ++i) {
        int u = x + dx2[i], v = y + dy2[i];
        if (u < 1 || u > n || v < 1 || v > m || vis[u][v]) {
          continue;
        }
        vis[u][v] = true;
        dist[u][v] = std::min(dist[u][v], w + 1);
        a[u][v] = '.';
        if (std::abs(u - x) == 2) {
          if (u > x) {
            a[u - 1][v] = '.';
          } else {
            a[u + 1][v] = '.';
          }
        } else {
          if (v > y) {
            a[u][v - 1] = '.';
          } else {
            a[u][v + 1] = '.';
          }
        }
        pq.push({dist[u][v], u, v});
      }
    }
  };

  bfs();

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j) {
  //     std::cout << dist[i][j] << " \n"[j == m];
  //   }
  // }

  std::cout << dist[ex][ey] << "\n";
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