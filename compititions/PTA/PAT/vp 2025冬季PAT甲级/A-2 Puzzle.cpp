#include <bits/stdc++.h>

using i64 = long long;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,m;
  std::cin >> n >> m;

  auto ans = std::vector(n+1,std::vector<int>(m+1));

  std::unordered_map<int,std::vector<int>> map;
  for(int i = 0; i < n*m; i++){
    int num;
    std::cin >> num;
    for(int j = 0; j < 4; j++){
      int x;
      std::cin >> x;
      map[num].push_back(x);
    }
  }

  std::vector<std::vector<bool>> vis(n+1,std::vector<bool>(m+1));
  for(auto [u,v]:map){
    if(v[0]==0 && v[2]==0){
      ans[1][1] = u;
      vis[1][1] = true;
      break;
    }
  }

  auto dfs = [&](auto &&self,int x,int y)->void {
    int num = ans[x][y];
    for(int i = 0; i < 4; i++){
      int to = map[num][i];
      if(to == 0){
        continue;
      }
      if(i == 0){
        if(vis[x-1][y]){
          continue;
        }
        ans[x-1][y] = to;
        vis[x-1][y] = true;
        self(self,x-1,y);
      }else if(i == 1){
        if(vis[x+1][y]){
          continue;
        }
        ans[x+1][y] = to;
        vis[x+1][y] = true;
        self(self,x+1,y);
      }else if(i == 2){
        if(vis[x][y-1]){
          continue;
        }
        ans[x][y-1] = to;
        vis[x][y-1] = true;
        self(self,x,y-1);
      }else{
        if(vis[x][y+1]){
          continue;
        }
        ans[x][y+1] = to;
        vis[x][y+1] = true;
        self(self,x,y+1);
      }
    }
  };

  dfs(dfs,1,1);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      std::cout << ans[i][j] << " \n"[j==m];
    }
  }
}