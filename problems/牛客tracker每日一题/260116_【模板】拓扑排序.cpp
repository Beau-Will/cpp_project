#include <iostream>
#include <vector>
#include <queue>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n+1);
  std::vector<int> in(n+1);
  for(int i = 0; i < m; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    in[v]++;
  }

  std::vector<int> ans;

  auto topoSort = [&](){
    std::queue<int> q;

    for(int i = 1; i <= n; i++){
      if(in[i] == 0){
        q.push(i);
      }
    }

    while(q.size()){
      auto u = q.front();
      q.pop();
      ans.push_back(u);

      for(auto v:adj[u]){
        if(--in[v] == 0){
          q.push(v);
        }
      }
    }
  };

  topoSort();

  if(ans.size() != n){
    std::cout << "-1\n";
    return 0;
  }

  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
  }
}