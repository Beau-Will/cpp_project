#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m,k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> adj(n+1);

  std::vector<std::vector<int>> map(k+1);
  for(int i = 0; i < n; i++){
    int ai;
    std::cin >> ai;
    map[ai].push_back(i+1);
  }

  for(int i = 0; i < m; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> dist(n+1,inf1);

  auto bfs = [&](){
    std::vector<int> vis(n+1);
    std::queue<int> q;

    q.push(1);
    dist[1] = 0;
    vis[1] = true;

    while(q.size()){
      auto u = q.front();
      q.pop();

      for(auto v:adj[u]){
        if(vis[v]){
          continue;
        }

        dist[v] = dist[u]+1;
        vis[v] = true;
        q.push(v);
      }
    }
  };

  bfs();

  for(int i = 1; i <= k; i++){
    int max = 0;
    
    for(int j:map[i]){
      max = std::max(max,dist[j]);
    }

    std::cout << max << " \n"[i==k];
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