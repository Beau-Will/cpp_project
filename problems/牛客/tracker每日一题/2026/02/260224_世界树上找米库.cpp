#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int inf = 1E9;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < n - 1; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> dist(n + 1, inf);
  auto bfs = [&](){
    std::vector<bool> vis(n + 1);
    std::queue<int> q;
    
    for(int i = 1; i <= n; i++){
      if(adj[i].size() == 1){
        q.push(i);
        dist[i] = 0;
        vis[i] = true;
      }
    }

    while(q.size()){
      auto u = q.front();
      q.pop();

      for(const auto& v : adj[u]){
        if(vis[v]){
          continue;
        }
        dist[v] = dist[u] + 1;
        vis[v] = true;
        q.push(v);
      }
    }
  };

  bfs();

  int max = *std::max_element(dist.begin() + 1, dist.end());
  std::vector<int> ans;
  for(int i = 1; i <= n; i++){
    if(dist[i] == max){
      ans.push_back(i);
    }
  }

  std::cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}

int main() {
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