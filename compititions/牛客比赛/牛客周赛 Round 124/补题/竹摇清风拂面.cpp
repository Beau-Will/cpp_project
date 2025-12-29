#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<i64> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::string t = " "+s+s;
  std::vector<i64> b(n*2+1);
  for(int i = 1; i <= n; i++){
    b[i] = a[i];
    b[n+i] = a[i];
  }

  std::vector<std::vector<i64>> dp(n*2+1,std::vector<i64>(n*2+1,inf2));

  //初始化区间长度为2
  for(int l = 1; l+1 <= n*2; l++){
    if(t[l] == t[l+1]){
      dp[l][l+1] = b[l]*b[l+1];
    }
  }

  for(int len = 4; len <= n; len+=2){
    for(int l = 1; l+len-1 <= n*2; l++){
      int r = l+len-1;
      //[l,r]
      if(t[l] == t[r]){
        dp[l][r] = std::min(dp[l][r],dp[l+1][r-1]+b[l]*b[r]);
      }
      //枚举分割点i,[l,i]和[i+1,r]
      for(int i = l; i < r; i++){
        dp[l][r] = std::min(dp[l][r],dp[l][i]+dp[i+1][r]);
      }
    }
  }

  i64 ans = inf2;
  for(int l = 1; l <= n; l++){
    ans = std::min(ans,dp[l][l+n-1]);
  }

  std::cout << (ans>=inf2?-1:ans) << "\n";
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