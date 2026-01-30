#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  auto g = std::vector(n+2,std::vector<int>(n+2));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      std::cin >> g[i][j];
    }
  }

  std::vector<int> dx = {-1,1,0,0};
  std::vector<int> dy = {0,0,-1,1};

  auto update = [&](int x,int y){
    int min = 1E9+1,max = -1E9-1;

    for(int i = 0; i < 4; i++){
      int u = x+dx[i],v = y+dy[i];
      min = std::min(min,g[u][v]);
      max = std::max(max,g[u][v]);
    }

    if(max < g[x][y]){
      g[x][y] = max;
    }
    if(min > g[x][y]){
      g[x][y] = min;
    }
  };

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      update(i,j);
      if(g[i][j] != 0){
        std::cout << "NO\n";
        return 0;
      }
    }
  }

  std::cout << "YES\n";
}