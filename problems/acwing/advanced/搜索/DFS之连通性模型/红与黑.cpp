#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  while(std::cin >> m >> n){
    if(n==0 && m==0){
      break;
    }
    
    auto g = std::vector(n,std::vector<char>(m));

    int sx,sy;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        std::cin >> g[i][j];
        if(g[i][j] == '@'){
          sx = i,sy = j;
        }
      }
    }

    int ans = 0;

    auto vis = std::vector(n,std::vector<bool>(m));

    std::vector<int> dx = {-1,1,0,0};
    std::vector<int> dy = {0,0,-1,1};

    auto dfs = [&](auto &&self,int x,int y)->void {
      ans++;
      vis[x][y] = true;
      for(int i = 0; i < 4; i++){
        int u = x+dx[i],v = y+dy[i];
        if(u<0 || u>=n || v<0 || v>=m || vis[u][v] || g[u][v]=='#' || g[u][v]=='@'){
          continue;
        }
        self(self,u,v);
      }
    };

    dfs(dfs,sx,sy);

    std::cout << ans << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}