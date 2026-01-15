#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n,w,h;
  std::cin >> n >> w >> h;

  std::vector<std::tuple<int,int,int>> a(n+1);
  for(int i = 1; i <= n; i++){
    int wi,hi,idx = i;
    std::cin >> wi >> hi;

    a[i] = {wi,hi,idx};
  }

  std::sort(a.begin()+1,a.end());

  std::vector<int> dp(n+1);
  std::unordered_map<int,int> prev;

  int max = 0,idx = -1;
  for(int i = 1; i <= n; i++){
    auto [wi,hi,_i] = a[i];
    if(w < wi && h < hi){
        dp[i] = 1;
    }else{
        dp[i] = -1E9;
    }
    
    for(int j = 1; j < i; j++){
        auto [wj,hj,_j] = a[j];
        if(wi>wj && hi>hj){
            if(dp[i] < dp[j]+1){
                prev[i] = j;
                dp[i] = dp[j]+1;
            }
        }
    }
    if(dp[i] > max){
        max = dp[i];
        idx = i;
    }
  }

  std::vector<int> ans;
  if(max){
    ans.push_back(std::get<2>(a[idx]));
  } 
  
  int t = idx;
  while(prev[t]){
    t = prev[t];
    ans.push_back(std::get<2>(a[t]));
  }

  std::reverse(ans.begin(),ans.end());

  std::cout << max << "\n";
  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}