#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  int sx = -1, sy = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '@'){
        sx = i;
        sy = j;
      }
    }
  }

  constexpr std::array dx = {-1, 1, 0, 0};
  constexpr std::array dy = {0, 0, -1, 1};
  auto bfs = [&](){
    std::vector vis(n, std::vector<bool>(m));
    std::queue<std::array<int, 2>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    int res = 0;

    while(q.size()){
      auto [x, y] = q.front();
      q.pop();

      if(g[x][y] == '!'){
        res++;
      }

      for(int i = 0; i < 4; i++){
        int u = x + dx[i], v = y + dy[i];
        if(u < 0 || u >= n || v < 0 || v >= m || vis[u][v] || g[u][v] == '#'){
          continue;
        }
        vis[u][v] = true;
        q.push({u, v});
      }
    }

    return res;
  };

  std::cout << bfs() << "\n";

  return 0;
}