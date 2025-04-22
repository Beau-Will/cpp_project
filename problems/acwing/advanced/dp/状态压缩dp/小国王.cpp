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
  int n,m;
  std::cin >> n >> m;

  auto check = [&](int x){
    for(int i = 0; i < n-1; ++i){
      if((x>>i&1) && (x>>(i+1)&1)){
        return false;
      }
    }
    return true;
  };

  std::vector<int> a;
  for(int i = 0; i < (1<<n); ++i){
    if(check(i)){
      a.push_back(i);
    }
  }

  std::map<int,std::vector<int>> b;
  for(auto &ai:a){
    for(auto &bi:a){
      if(!(ai&bi) && check(ai|bi)){
        b[ai].push_back(bi);
      }
    }
  }

  auto dp = std::vector(n+1,std::vector(m+1,std::vector<i64>(1+(1<<n))));

  dp[0][0][0] = 1;

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      for(auto &ai:a){
        for(auto bi:b[ai]){
          if(j>=__builtin_popcount(ai)){
            dp[i][j][ai] += dp[i-1][j-__builtin_popcount(ai)][bi];
          }
        }
      }
    }
  }

  i64 ans = 0;
  for(auto &ai:a){
    ans += dp[n][m][ai];
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