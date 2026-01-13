#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  for(int i = 0; i < n; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> color(n+1);
  std::vector<bool> vis(n+1);

  std::function<void(int)> dfs = [&](int u){
    vis[u] = true;

    for(auto v:adj[u]){
      if(vis[v]){
        continue;
      }

      color[v] = 1-color[u];
      dfs(v);
    }
  };

  dfs(1);

  auto check = [&](){
    for(int u = 1; u <= n; u++){
      for(auto v:adj[u]){
        if(color[u] == color[v]){
          color[v] = 3;
        }
      }
    }
  };

  check();

  for(int i = 1; i <= n; i++){
    std::cout << (color[i]==0?2:color[i]) << " \n"[i==n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}