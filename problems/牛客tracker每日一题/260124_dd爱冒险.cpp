#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  auto g = std::vector(n,std::vector<int>(n));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin >> g[i][j];
    }
  }

  auto dp = std::vector(1<<n,std::vector(n,std::vector(2,std::vector<int>(2,1E9))));

  for(int i = 0; i < n; i++){
    dp[1<<i][i][0][0] = 0;
  }

  for(int mask = 0; mask < (1<<n); mask++){
    for(int u = 0; u < n; u++){
      if(!((mask>>u)&1)){
        continue;
      }
      for(int z = 0; z < 2; z++){
        for(int d = 0; d < 2; d++){
          if(dp[mask][u][z][d] == 1E9){
            continue;
          }

          for(int v = 0; v < n; v++){
            if((mask>>v) & 1){
              continue;
            }

            int next = mask | (1<<v);
            
            if(dp[next][v][z][d] > dp[mask][u][z][d] + g[u][v]){
              dp[next][v][z][d] = dp[mask][u][z][d] + g[u][v];
            }

            if(z == 0){
              if(dp[next][v][1][d] > dp[mask][u][0][d]){
                dp[next][v][1][d] = dp[mask][u][0][d];
              }
            }

            if(d == 0){
              if(dp[next][v][z][1] > dp[mask][u][z][0]+g[u][v]*2){
                dp[next][v][z][1] = dp[mask][u][z][0]+g[u][v]*2;
              }
            }
          }
        }
      }
    }
  }

  int ans = 1E9;

  for(int i = 0; i < n; i++){
    ans = std::min(ans,dp[(1<<n)-1][i][1][1]);
  }

  std::cout << ans << "\n";
}