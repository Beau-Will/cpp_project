#include <bits/stdc++.h>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<std::vector<int>> adj(n+1);
  for(int i = 1; i <= n; i++){
    if((i<<1) <= n){
      adj[i<<1].push_back(i);
      adj[i].push_back(i<<1);
    }
    if(((i<<1)|1) <= n){
      adj[(i<<1)|1].push_back(i);
      adj[i].push_back((i<<1)|1);
    }
  }

  std::vector<int> dep(n+1);
  int maxDep = 0;

  std::function<void(int,int)> dfs = [&](int u,int fa){
    maxDep = std::max(maxDep,dep[u]);

    for(const auto& v:adj[u]){
      if(v == fa){
        continue;
      }
      dep[v] = dep[u]+1;
      dfs(v,u);
    }
  };

  dep[1] = 1;
  dfs(1,0);

  std::vector<i64> sum(maxDep+1);
  for(int i = 1; i <= n; i++){
    sum[dep[i]] += a[i];
  }

  i64 max = 0;
  int ans = -1;
  for(int i = 1; i <= maxDep; i++){
    if(sum[i] > max){
      max = sum[i];
      ans = i;
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