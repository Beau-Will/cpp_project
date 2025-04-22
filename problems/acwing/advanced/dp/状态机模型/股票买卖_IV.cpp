#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  auto dp = std::vector(k+1,std::vector<int>(2,-inf1));

  dp[0][0] = 0;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      dp[j][0] = std::max(dp[j][0],dp[j][1]+a[i]);
      dp[j][1] = std::max(dp[j][1],dp[j-1][0]-a[i]);
    }
  }

  int ans = 0;
  for(int i = 0; i <= k; ++i){
    for(int j = 0; j < 2; ++j){
      ans = std::max(ans,dp[i][j]);
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}