#include <bits/stdc++.h>
#include <bit>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  i64 n;
  int k;
  std::cin >> n >> k;

  int cnt1 = std::__popcount(n);

  if(k >= 32){
    std::cout << cnt1+k-1 << "\n";
    return;
  }

  auto dp = std::vector(65,std::vector(33,std::vector(2,inf1)));
  dp[0][0][0] = 0;

  for(int i = 0; i < 64; i++){
    int ni = (n>>i)&1LL;
    for(int j = 0; j <= k; j++){
      for(int c = 0; c < 2; c++){
        if(dp[i][j][c] >= inf1){
          continue;
        }

        int cur = ni+c;
        dp[i+1][j][cur>>1] = std::min(dp[i+1][j][cur>>1],dp[i][j][c]+(cur&1));

        if(j < k){
          dp[i+1][j+1][(cur+1)>>1] = std::min(dp[i+1][j+1][(cur+1)>>1],dp[i][j][c]+((cur+1)&1));
        }
      }
    }
  }

  int min = inf1;
  for(int i = 0; i <= k; i++){
    for(int j = 0; j < 2; j++){
      if(dp[64][i][j] >= inf1){
        continue;
      }
      min = std::min(min,dp[64][i][j]+j);
    }
  }

  std::cout << cnt1+k-min << "\n";
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