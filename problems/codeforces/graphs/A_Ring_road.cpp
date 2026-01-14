#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  std::map<std::tuple<int,int>,int> map;

  for(int i = 0; i < n; i++){
    int u,v,w;
    std::cin >> u >> v >> w;

    adj[u].push_back(v);
    adj[v].push_back(u);
    map[{u,v}] = w;
  }

  std::vector<bool> vis(n+1);
  std::vector<int> dfn;

  std::function<void(int u)> dfs = [&](int u){
    vis[u] = true;

    for(auto v:adj[u]){
      if(vis[v]){
        continue;
      }

      dfs(v);
    }

    dfn.push_back(u);
  };

  dfs(1);

  auto rev = dfn;
  std::reverse(rev.begin(),rev.end());

  int ans1 = 0;
  for(int i = 0; i < dfn.size()-1; i++){
    if(map[{dfn[i],dfn[i+1]}] == 0){
      ans1 += map[{dfn[i+1],dfn[i]}];
    }
  }

  if(map[{dfn.back(),dfn.front()}] == 0){
    ans1 += map[{dfn.front(),dfn.back()}];
  }

  int ans2 = 0;
  for(int i = 0; i < rev.size()-1; i++){
    if(map[{rev[i],rev[i+1]}] == 0){
      ans2 += map[{rev[i+1],rev[i]}];
    }
  }

  if(map[{rev.back(),rev.front()}] == 0){
    ans2 += map[{rev.front(),rev.back()}];
  }

  std::cout << std::min(ans1,ans2) << "\n";
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