#include <iostream>
#include <vector>
#include <algorithm>

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, inf);
  dp[0] = 0;
  for(int i = 6; i <= n; i++){
    dp[i] = dp[i - 6] + 1;
    if(i >= 8){
      dp[i] = std::min(dp[i], dp[i - 8] + 1);
    }
  }

  std::cout << (dp[n] >= inf ? -1 : dp[n]) << "\n";

  return 0;
}