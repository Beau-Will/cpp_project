#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  auto g = std::vector(n,std::vector<char>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin >> g[i][j];
    }
  }
  int x1,y1,x2,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::vector<int> dx = {-1,1,0,0};
  std::vector<int> dy = {0,0,-1,1};

  auto vis = std::vector(n,std::vector<bool>(n));

  auto dfs = [&](auto &&self,int x,int y)->bool {
    if(g[x][y] == '#'){
      return false;
    }
    if(x==x2 && y==y2){
      return true;
    }

    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
      int u = x+dx[i],v = y+dy[i];
      if(u<0 || u>=n || v<0 || v>=n || vis[u][v]){
        continue;
      }
      if(self(self,u,v)){
        return true;
      }
    }
    return false;
  };

  std::cout << (dfs(dfs,x1,y1)?"YES\n":"NO\n");
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}