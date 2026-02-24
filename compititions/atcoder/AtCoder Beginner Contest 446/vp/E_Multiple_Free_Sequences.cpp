#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int m, a, b;
  std::cin >> m >> a >> b;

  int n = m * m;
  std::vector<std::vector<int>> g(n);

  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      g[j * m + (a * j + b * i) % m].push_back(i * m + j);
    }
  }

  std::vector<bool> vis(n);
  std::queue<int> q;
  for(int j = 0; j < m; j++){
    q.push(j);
    vis[j] = true;
    if(j){
      q.push(j * m);
      vis[j * m] = true;
    }
  }

  while(q.size()){
    auto u = q.front();
    q.pop();

    for(const auto& v : g[u]){
      if(vis[v]){
        continue;
      }
      q.push(v);
      vis[v] = true;
    }
  }

  std::cout << std::count(vis.begin(), vis.end(), false) << "\n";
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