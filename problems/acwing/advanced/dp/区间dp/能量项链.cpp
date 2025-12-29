#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n*2+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
    a[i+n] = a[i];
  }

  auto dp = std::vector(n*2+1,std::vector<int>(n*2+1));

  for(int len = 3; len <= n+1; len++){
    for(int l = 1; l+len-1 <= n*2; l++){
      int r = l+len-1;

      for(int mid = l+1; mid < r; mid++){
        dp[l][r] = std::max(dp[l][r],dp[l][mid]+dp[mid][r]+a[l]*a[mid]*a[r]);
      }
    }
  }

  int ans = 0;
  for(int l = 1; l+n <= n*2; l++){
    int r = l+n;
    ans = std::max(ans,dp[l][r]);
  }

  std::cout << ans << "\n";
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

  return 0;
}