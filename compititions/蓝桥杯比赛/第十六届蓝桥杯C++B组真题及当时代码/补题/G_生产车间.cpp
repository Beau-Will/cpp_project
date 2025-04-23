#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> w(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;

    if(u>v){
      std::swap(u,v);
    }
    adj[u].push_back(v);
  }

  auto cap = std::vector(n+1,std::vector<int>());

  auto dfs = [&](auto &&self,int u) ->int {
    if(adj[u].size()==0){
      cap[u].push_back(w[u]);
      return cap[u].size();
    }

    auto dp = std::vector(w[u]+1,std::vector<int>(adj[u].size()+1,0));
    dp[0][0] = 1;

    for(int i = 0; i <= w[u]; ++i){
      for(int j = 1; j <= adj[u].size(); ++j){
        if(i==0 || dp[i][j-1]){
          dp[i][j] = 1;
        }else{
          int v = adj[u][j-1];
          int len;
          if(cap[v].size()==0){
            len = self(self,v);
          }else{
            len = cap[v].size();
          }
          for(int k = 0; k < len; ++k){
            if(i-cap[v][k]>=0 && dp[i-cap[v][k]][j-1]){
              dp[i][j] = 1;
              break;
            }
          }
        }

        if(j==adj[u].size()&&dp[i][j]){
          cap[u].push_back(i);
        }
      }
    }

    return cap[u].size();
  };

  dfs(dfs,1);

  std::cout << *max_element(all(cap[1])) << "\n";
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