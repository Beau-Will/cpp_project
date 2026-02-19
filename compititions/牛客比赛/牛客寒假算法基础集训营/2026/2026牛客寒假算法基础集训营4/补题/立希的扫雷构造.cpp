#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector dp(10, std::vector(10, std::vector(1 << 9, std::vector<int>(40, -inf1))));
std::vector pre(10, std::vector(10, std::vector(1 << 9, std::vector<int>(40, -1))));

void solve(){
  int n, m, k;
  std::cin >> n >> m >> k;

  int f = 0;
  if(k * 2 >= n * m){
    k = n * m - k;
    f = 1;
  }

  std::array<int, 2> ans = {-1, -1};
  for(int i = 0; i < (1 << m); i++){
    ans = std::max(ans, {dp[m][n][i][k], i});
  }

  auto [x, y] = ans;
  std::cout << x << "\n";

  for(int i = n, j = y, cnt = k; i >= 1; i--){
    char a = '*', b = '.';
    if(f){
      std::swap(a, b);
    }
    for(int o = 0; o < m; o++){
      if(j >> o & 1){
        std::cout << a;
      }else{
        std::cout << b;
      }
    }
    std::cout << "\n";
    int t = __builtin_popcount(j);
    j = pre[m][i][j][cnt];
    cnt -= t;
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n = 9, k = n * n / 2;
  for(int m = 1; m <= n; m++){
    std::vector dis(1 << m, std::vector<int>(1 << m));
    k = m * n / 2;
    
    for(int i = 0; i < (1 << m); i++){
      for(int j = 0; j < (1 << m); j++){
        auto &t = dis[i][j];
        for(int p = 0; p < m; p++){
          if(!(i >> p & 1)){
            t += j >> p & 1;
            t += j >> (p - 1) & 1;
            t += j >> (p + 1) & 1;
          }
          if(!(j >> p & 1)){
            t += i >> p & 1;
            t += i >> (p - 1) & 1;
            t += i >> (p + 1) & 1;
            t += j >> (p - 1) & 1;
            t += j >> (p + 1) & 1;
          }
        }
      }
    }

    for(int i = 0; i < (1 << m); i++){
      int cnt = __builtin_popcount(i);
      dp[m][1][i][cnt] = 0;
      for(int p = 0; p < m; p++){
        if(!(i >> p & 1)){
          int t = 0;
          t += i >> (p - 1) & 1;
          t += i >> (p + 1) & 1;
          dp[m][1][i][cnt] += t;
        }
      }
    }

    for(int i = 2; i <= n; i++){
      for(int j = 0; j < (1 << m); j++){
        int cnt = __builtin_popcount(j);

        for(int l = 0; l < (1 << m); l++){
          for(int o = cnt; o <= k; o++){
            if(dp[m][i][j][o] < dp[m][i - 1][l][o - cnt] + dis[l][j]){
              dp[m][i][j][o] = std::max(dp[m][i][j][o], dp[m][i - 1][l][o - cnt] + dis[l][j]);
              pre[m][i][j][o] = l;
            }
          }
        }
      }
    }
  }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}