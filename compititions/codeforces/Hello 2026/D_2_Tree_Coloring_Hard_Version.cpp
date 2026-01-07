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

  std::vector<int> dep(n+1),son(n+1),cnt(n+1);
  int max = 0;

  dep[1] = 1;
  std::queue<int> q;
  q.push(1);

  while(q.size()){
    auto u = q.front();
    q.pop();

    int d = dep[u];
    cnt[d]++;
    max = std::max(max,d);
    for(auto v:adj[u]){
      if(dep[v] == 0){
        dep[v] = d+1;
        son[u]++;
        q.push(v);
      }
    }
  }

  int ans = 0;
  for(int d = 1; d <= max; d++){
    ans = std::max(ans,cnt[d]);
  }

  for(int u = 1; u <= n; u++){
    ans = std::max(ans,son[u]+1);
  }

  std::cout << ans << "\n";

  std::vector<int> parent(n+1, 0);
  std::vector<std::vector<int>> children(n+1);
  
  std::function<void(int,int)> dfs = [&](int u, int f) {
    parent[u] = f;
    for(auto v:adj[u]){
      if(v != f){
        children[u].push_back(v);
        dfs(v, u);
      }
    }
  };
  
  dfs(1, 0);

  std::vector<std::vector<int>> depth_nodes(max+1);
  for(int u = 1; u <= n; u++){
    depth_nodes[dep[u]].push_back(u);
  }

  std::vector<int> color(n+1, 0);
  std::vector<int> used_color_cnt(ans+1, 0);
  
  color[1] = 1;
  used_color_cnt[1] = 1;

  for(int d = 2; d <= max; d++){
    for(auto u : depth_nodes[d]){
      std::vector<bool> forbidden(ans+1, false);
      forbidden[color[parent[u]]] = true;
      
      for(auto v : children[parent[u]]){
        if(v != u && color[v] != 0){
          forbidden[color[v]] = true;
        }
      }
      
      int chosen = -1;
      for(int c = 1; c <= ans; c++){
        if(!forbidden[c]){
          if(chosen == -1 || used_color_cnt[c] < used_color_cnt[chosen]){
            chosen = c;
          }
        }
      }
      
      color[u] = chosen;
      used_color_cnt[chosen]++;
    }
  }

  std::vector<std::vector<int>> groups(ans+1);
  for(int u = 1; u <= n; u++){
    groups[color[u]].push_back(u);
  }
  
  for(int c = 1; c <= ans; c++){
    std::cout << groups[c].size();
    for(int i = 0; i < groups[c].size(); i++){
      std::cout << " " << groups[c][i];
    }
    std::cout << "\n";
  }
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