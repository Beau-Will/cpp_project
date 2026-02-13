#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr std::array<int, 4> dx = {0, 0, -1, 1};
constexpr std::array<int, 4> dy = {-1, 1, 0, 0};

void solve(){
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;

  std::vector<std::pair<int, int>> bla(a);
  std::vector<std::tuple<int, int, int>> blu(b);
  std::vector map(n + 1, std::vector<int>(m + 1));

  for(int i = 0; i < a; i++){
    auto& [x, y] = bla[i];
    std::cin >> x >> y;
  }

  for(int i = 0; i < b; i++){
    auto& [x, y, t] = blu[i];
    std::cin >> x >> y >> t;
    map[x][y] = t;
  }

  std::vector dist(n + 1, std::vector<i64>(m + 1, inf2));

  auto dijkstra = [&](){
    using Node = std::tuple<i64, int, int>;
    std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;

    for(int i = 0; i < a; i++){
      auto [x, y] = bla[i];
      heap.push({0, x, y});
      dist[x][y] = 0;
    }

    while(heap.size()){
      auto [t, x, y] = heap.top();
      heap.pop();

      if(t != dist[x][y]){
        continue;
      }

      for(int i = 0; i < 4; i++){
        int u = x + dx[i], v = y + dy[i];
        if(u < 1 || u > n || v < 1 || v > m){
          continue;
        }

        i64 w = t + 1;
        if(map[u][v]){
          w = std::max(w, static_cast<i64>(map[u][v]));
        }
        
        if(w < dist[u][v]){
          dist[u][v] = w;
          heap.push({w, u, v});
        }
      }
    }
  };
  
  dijkstra();

  i64 ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ans = std::max(ans, dist[i][j]);
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}