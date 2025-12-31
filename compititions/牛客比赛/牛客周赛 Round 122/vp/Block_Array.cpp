#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> dp(n+1);
  int last = -1;

  i64 ans = 0;
  for(int i = 1; i <= n; i++){
    if(last==-1 || a[i]!=a[i-1]){
      last = i;
    }
    if(i-last+1 >= a[i]){
      dp[i] = dp[i-a[i]]+1;
    }else{
      dp[i] = 0;
    }

    ans += dp[i];
  }

  std::cout << ans << "\n";
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