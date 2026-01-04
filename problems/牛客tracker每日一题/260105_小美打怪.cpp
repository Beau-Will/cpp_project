#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n,H,A;
  std::cin >> n >> H >> A;

  std::vector<std::pair<int,int>> v(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> v[i].first;
  }
  for(int i = 1; i <= n; i++){
    std::cin >> v[i].second;
  }

  std::sort(v.begin()+1,v.end(),std::greater());

  std::vector<int> dp(n+1);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(H>v[i].first && A>v[i].second){
      dp[i] = 1;
    }else{
      continue;
    }
    for(int j = 1; j < i; j++){
      if(v[j].first>v[i].first && v[j].second>v[i].second){
        dp[i] = std::max(dp[i],dp[j]+1);
      }
    }
    ans = std::max(ans,dp[i]);
  }

  std::cout << ans << "\n";
}