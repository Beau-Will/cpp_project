#include <iostream>
#include <vector>
#include <algorithm>

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  std::vector<int> in(n+1);
  for(int i = 1; i < n; i++){
    int u,v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    in[v]++;
  }

  int root = -1;
  for(int i = 1; i <= n; i++){
    if(in[i] == 0){
      root = i;
    }
  }

  for(int i = 1; i <= n; i++){
    std::sort(adj[i].begin(),adj[i].end());
  }

  auto dfs1 = [&](auto &&self1,int u)->void {
    //先序:根 左 右
    std::cout << u << " ";

    for(auto v:adj[u]){
      self1(self1,v);
    }
  };

  dfs1(dfs1,root);
  std::cout << "\n";

  auto dfs2 = [&](auto &&self2,int u)->void {
    //中序:左 根 右
    if(adj[u].size() == 0){
      std::cout << u << " ";
      return;
    }

    if(adj[u].size() == 1){
      int v = adj[u].front();
      if(v > u){
        self2(self2,v);
        std::cout << u << " ";
      }else{
        std::cout << u << " ";
        self2(self2,v);
      }
      return;
    }

    bool hasLast = false;
    for(auto v:adj[u]){
      if(hasLast){
        std::cout << u << " ";
      }
      self2(self2,v);
      hasLast = true;
    }
  };

  dfs2(dfs2,root);
  std::cout << "\n";

  auto dfs3 = [&](auto &&self3,int u)->void {
    //后序:左 右 根
    for(auto v:adj[u]){
      self3(self3,v);
    }

    std::cout << u << " ";
  };

  dfs3(dfs3,root);
  std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    for(; T--;){
        solve();
    }

    return 0;
}