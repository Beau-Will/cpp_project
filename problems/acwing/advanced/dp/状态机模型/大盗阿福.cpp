#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  auto dp = std::vector(n+1,std::vector<int>(2,-inf1));

  dp[0][0] = 0;

  for(int i = 1; i <= n; ++i){
    dp[i][0] = std::max(dp[i-1][1],dp[i-1][0]);
    dp[i][1] = dp[i-1][0]+a[i];
  }

  std::cout << std::max(dp[n][0],dp[n][1]) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}