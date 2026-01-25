#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  for(int i = 1; i < n; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(n == 1){
    std::cout << "1\n";
    return;
  }

  std::vector<int> par(n+1,-1);
  std::vector<int> siz(n+1);

  std::function<void(int,int)> dfs = [&](int u,int fa){
    siz[u] = 1;
    for(const auto& v:adj[u]){
      if(v == fa){
        continue;
      }
      par[v] = u;
      dfs(v,u);
      siz[u] += siz[v];
    }
  };

  dfs(1,-1);

  int ans = 0;
  for(int u = 1; u <= n; u++){
    bool isok = true;

    if(par[u] != -1 && (n-siz[u]) % 2 == 0){
      isok = false;
    }
    for(const auto& v:adj[u]){
      if(v == par[u]){
        continue;
      }
      if(siz[v] % 2 == 0){
        isok = false;
        break;
      }
    }
    if(isok){
      ans++;
    }
  }

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