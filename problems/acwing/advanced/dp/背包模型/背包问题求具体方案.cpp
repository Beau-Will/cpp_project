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
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+2),b(n+2);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i] >> b[i];
  }

  std::vector<std::vector<int>> dp(n+2,std::vector<int>(m+1));
  for(int i = n; i >= 1; --i){
    for(int j = m; j >= 0; --j){
      dp[i][j] = dp[i+1][j];
      if(j>=a[i]){
        dp[i][j] = std::max(dp[i+1][j],dp[i+1][j-a[i]]+b[i]);
      }
    }
  }

  int cur = m;
  std::vector<int> ans;
  for(int i = 1; i <= n; ++i){
    if(cur >= a[i]&&dp[i+1][cur-a[i]]+b[i]==dp[i][cur]){
      ans.push_back(i);
      cur -= a[i];
    }
  }

  std::sort(all(ans));

  for(int i = 0; i < ans.size(); ++i){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
  }
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