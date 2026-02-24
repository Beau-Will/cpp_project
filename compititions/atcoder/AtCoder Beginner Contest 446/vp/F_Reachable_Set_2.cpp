#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
  }

  std::vector<bool> vis(n + 1);
  std::vector<std::queue<int>> q(n + 1);
  q[1].push(1);
  vis[1] = true;
  int s = 1;

  for(int i = 1, j = 1; i <= n; i++){
    while(q[i].size()){
      int u = q[i].front();
      q[i].pop();

      for(const auto& v : adj[u]){
        if(vis[v]){
          continue;
        }
        q[std::max(i, v)].push(v);
        vis[v] = true;
        s++;
      }
    }

    while(j <= i && vis[j]){
      j++;
    }
    
    std::cout << (j == i + 1 ? s - i : -1) << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}