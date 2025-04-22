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

  int root = -1;
  std::vector<int> a(n+1),b(n+1);
  std::vector<std::vector<int>> adj(n+1);
  
  for(int i = 1; i <= n; ++i){
    int fa;
    std::cin >> a[i] >> b[i] >> fa;
    if(fa==-1){
      root = i;
    }else{
      adj[fa].push_back(i);
    }
  }
  
  auto dp = std::vector(n+1,std::vector<int>(m+1));

  auto dfs = [&](auto &&self,int u)->void {
    for(auto &v:adj[u]){
      self(self,v);
      for(int j = m-a[u]; j >= 0; --j){
        for(int k = j; k >= 0; --k){
          dp[u][j] = std::max(dp[u][j],dp[u][j-k]+dp[v][k]);
        }
      }
    }

    for(int j = m; j >= a[u]; --j){
      dp[u][j] = dp[u][j-a[u]]+b[u];
    }
    for(int j = 0; j < a[u]; ++j){
      dp[u][j] = 0;
    }
  };

  dfs(dfs,root);

  std::cout << dp[root][m] << "\n";
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