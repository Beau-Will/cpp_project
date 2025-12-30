#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  auto a = std::vector(n+1,std::vector<int>(n+1));
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j++){
      a[i][j] = (i-1)*n+j;
    }
  }

  std::vector<int> dx = {-1,1,0,0};
  std::vector<int> dy = {0,0,-1,1};
  auto get = [&](int x,int y){
    int ans = a[x][y];
    for(int i = 0; i < 4; i++){
      int u = x+dx[i],v = y+dy[i];
      if(u<1 || u>n || v<1 || v>n){
        continue;
      }
      ans += a[u][v];
    }
    return ans;
  };

  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      ans = std::max(ans,get(i,j));
    }
  }

  std::cout << ans << "\n";
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