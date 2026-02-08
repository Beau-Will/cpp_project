#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

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

  int maxDeg = 0;
  for(int i = 1; i <= n; i++){
    maxDeg = std::max(maxDeg, static_cast<int>(adj[i].size()));
  }

  if(maxDeg >= 4){
    std::cout << "0\n";
    return;
  }

  int ans = n;
  for(int i = 1; i <= n; i++){
    if(adj[i].size() == 3){
      ans--;
    }
  }

  std::cout << ans << "\n";
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