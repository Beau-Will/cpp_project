#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;
  s = "?" + s;

  std::vector dp(n + 1, std::vector(2, std::vector<int>(4, inf)));

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      dp[2][i][i ^ j] = std::min(dp[2][i][i ^ j], ((s[2] ^ 48) != i) + ((s[1] ^ 48) != j));
    }
  }

  for(int i = 2; i < n; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k <= 3; k++){
        int x = dp[i][j][k];
        for(int t = 0; t < 2; t++){
          dp[i + 1][t][k + (t ^ j)] = std::min(dp[i + 1][t][k + (t ^ j)], x + (t != (s[i + 1] ^ 48)));
        }
      }
    }
  }

  int ans = inf;
  for(int i = 0; i < 2; i++){
    ans = std::min(ans, dp[n][i][3]);
  }

  std::cout << ans << "\n";

  return 0;
}