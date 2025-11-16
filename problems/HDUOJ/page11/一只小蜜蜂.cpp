#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<std::vector<int>> pos(3,std::vector<int>(30));
std::vector<std::vector<i64>> dp(3,std::vector<i64>(30));

void solve() {
  int st,ed;
  std::cin >> st >> ed;

  int i1,j1,i2,j2;
  for(int i = 1; i <= 2; i++){
    for(int j = 1; j <= 25; j++){
      if(pos[i][j]==st){
        i1 = i,j1 = j;
      }
      if(pos[i][j]==ed){
        i2 = i,j2 = j;
      }
    }
  }

  for(int i = 0; i < 3; i++){
    std::fill(dp[i].begin(),dp[i].end(),0);
  }

  dp[i1][j1] = 1;
  for(int j = j1; j <= j2; j++){
    for(int i = 1; i <= 2; i++){
      if(i==1){
        dp[i][j] += dp[i][j-1]+dp[i+1][j-1];
      }else{
        dp[i][j] += dp[i][j-1]+dp[i-1][j];
      }
    }
  }

  std::cout << dp[i2][j2] << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for(int i = 1; i <= 25; i++){
    for(int j = 1; j <= 2; j++){
      pos[j][i] = (i-1)*2+j;
    }
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}