#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve() {
  int sx = 0, sy = 0;
  int ex = 233, ey = 666;
  std::vector<std::vector<int>> dist(1001, std::vector<int>(1001, inf));
  std::vector<std::vector<bool>> vis(1001, std::vector<bool>(1001));

  auto bfs = [&]() {
    std::vector<int> dx = {1, 1, -1};
    std::vector<int> dy = {0, -1, 1};

    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});

    dist[sx][sy] = 0;
    vis[sx][sy] = true;

    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      for (int i = 0; i < 3; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (u < 0 || u > 1000 || v < 0 || v > 1000 || vis[u][v]) {
          continue;
        }
        vis[u][v] = true;
        dist[u][v] = dist[x][y] + 1;
        q.push({u, v});
      }
    }
  };

  bfs();

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