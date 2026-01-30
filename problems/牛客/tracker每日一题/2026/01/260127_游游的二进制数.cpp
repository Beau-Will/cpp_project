#include <iostream>
#include <vector>
#include <string>
#include <functional>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  i64 l,r;
  std::cin >> n >> l >> r;

  std::string s;
  std::cin >> s;

  std::vector<std::vector<int>> adj(n);
  for(int i = 0; i < n-1; i++){
    int u,v;
    std::cin >> u >> v;
    u--,v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  std::function<void(int,int,int,i64)> dfs = [&](int u,int fa,int cnt,i64 cur){
    if(cur > r){
      return;
    }
    if(cur >= l && cnt > 0){
      ans++;
    }

    for(const auto& v:adj[u]){
      if(v == fa){
        continue;
      }

      dfs(v,u,cnt+1,(cur<<1)+s[v]-'0');
    }
  };

  for(int u = 0; u < n; u++){
    dfs(u,-1,0,s[u]-'0');
  }

  std::cout << ans << "\n";
}