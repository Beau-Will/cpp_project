#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<i64> dp(51);
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= 50; i++){
    dp[i] += dp[i-1]+dp[i-2];
  }

  int n;
  while(std::cin >> n){
    std::cout << dp[n] << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}