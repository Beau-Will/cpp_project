#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin()+1,a.end());

  if(a[n] > n){
    std::cout << "-1\n";
    return 0;
  }

  std::vector<int> dp(n+1);
  for(int i = 1; i <= n; i++){
    dp[i] = 0;
    if(i >= a[i]){
      dp[i] = std::max(dp[i-1],dp[i-a[i]]+1);
    }
  }

  std::cout << dp[n] << "\n";
}