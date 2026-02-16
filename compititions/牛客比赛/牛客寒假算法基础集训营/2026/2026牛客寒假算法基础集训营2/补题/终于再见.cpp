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
    adj[v].push_back(u);
  }

  std::vector<int> cnt(n);
  for(int i = 1; i <= n; i++){
    cnt[adj[i].size()]++;
  }

  std::vector<int> ans(n + 1, inf1);
  std::vector<int> dist;
  for(int c = 0; c < n; c++){
    if(cnt[c] == 0){
      continue;
    }

    std::queue<int> q;
    dist.assign(n + 1, -1);

    for(int i = 1; i <= n; i++){
      if(adj[i].size() == c){
        q.push(i);
        dist[i] = 0;
      }
    }

    while(q.size()){
      auto u = q.front();
      q.pop();

      if(adj[u].size() < c){
        ans[u] = std::min(ans[u], dist[u]);
      }

      for(const auto& v : adj[u]){
        if(adj[v].size() < c && dist[v] == -1){
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << (ans[i] == inf1 ? -1 : ans[i]) << " \n"[i == n];
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