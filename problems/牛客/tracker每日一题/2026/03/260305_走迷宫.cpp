#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <array>

constexpr int inf = 1E9;
constexpr std::array dx = {0, 0, -1, 1};
constexpr std::array dy = {-1, 1, 0, 0};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  sx--, sy--, tx--, ty--;

  std::vector a(n, std::string(m, '?'));
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto bfs = [&](){
    std::vector dist(n, std::vector<int>(m, inf));
    std::vector vis(n, std::vector<bool>(m));
    std::queue<std::array<int, 2>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    vis[sx][sy] = true;

    while(q.size()){
      auto [x, y] = q.front();
      q.pop();

      if(x == tx && y == ty){
        return dist[x][y];
      }

      for(int i = 0; i < dx.size(); i++){
        int u = x + dx[i], v = y + dy[i];
        if(u < 0 || u >= n || v < 0 || v >= m || vis[u][v] || a[u][v] == '*'){
          continue;
        }
        dist[u][v] = dist[x][y] + 1;
        vis[u][v] = true;
        q.push({u, v});
      }
    }

    return -1;
  };

  std::cout << bfs() << "\n";

  return 0;
}