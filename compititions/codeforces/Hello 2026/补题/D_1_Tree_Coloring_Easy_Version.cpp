#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  for(int i = 0; i < n-1; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> dep(n+1),cnt(n+1),son(n+1);
  dep[1] = 1;

  std::function<void(int,int)> dfs = [&](int u,int fa){
    for(auto v:adj[u]){
      if(v == fa){
        continue;
      }

      dep[v] = dep[u]+1;
      son[u]++;
      dfs(v,u);
    }
  };

  dfs(1,0);

  for(int u = 1; u <= n; u++){
    cnt[dep[u]]++;
  }

  int ans = 0;
  for(int d = 1; d <= n; d++){
    if(cnt[d] == 0){
      break;
    }
    ans = std::max(ans,cnt[d]);
  }

  for(int u = 1; u <= n; u++){
    ans = std::max(ans,son[u]+1);
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}