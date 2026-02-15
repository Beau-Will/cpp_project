#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 n, a, b;
  std::cin >> n >> a >> b;
  i64 c = a + b;

  std::vector<i64> dp(113);
  for(int i = 1; i <= 112; i++){
    dp[i] = dp[i - 1];
    if(i >= 2){
      dp[i] = std::max(dp[i], dp[i - 2] + b);
    }
    if(i >= 7){
      dp[i] = std::max(dp[i], dp[i - 7] + a);
    }
    if(i >= 8){
      dp[i] = std::max(dp[i], dp[i - 8] + c);
    }
  }

  if(n < 113){
    std::cout << dp[n] << "\n";
    return;
  }

  i64 m = n - 113;
  i64 t1 = m / 2 + 1, t2 = m / 7 + 1, t3 = m / 8 + 1;
  i64 ans = std::max({t1 * b + dp[n - t1 * 2], t2 * a + dp[n - t2 * 7], t3 * c + dp[n - t3 * 8]});

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}