#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf = 1000000000;

void solve(){
  int n;
  std::cin >> n;
  
  std::vector<int> w(n+1);
  for(int i = 1; i <= n; ++i){
  	std::cin >> w[i];
  }
  
  auto adj = std::vector(n+1,std::vector<int>());

  for(int i = 2; i <= n; ++i){
    int fa;
    std::cin >> fa;
    adj[fa].push_back(i);
  }

  std::vector<int> siz(n+1);
  std::vector<i64> sum(n+1),dp(n+1);

  auto dfs = [&](auto &&self,int u) ->void {
    sum[u] = w[u];

    for(auto &v:adj[u]){
      self(self,v);
      sum[u] += sum[v];
    }

    std::sort(adj[u].begin(),adj[u].end(),[&](auto &t1,auto &t2){
      return sum[t1]*siz[t2]<sum[t2]*siz[t1];
    });

    siz[u] = 1;
    dp[u] = w[u];
    for(auto &v:adj[u]){
      dp[u] += dp[v]+sum[v]*siz[u];
      siz[u] += siz[v];
    }
  };

  dfs(dfs,1);

  std::cout << dp[1] << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
//  std::cin >> t;
  while(t--){
    solve();
  }

  return 0;
}