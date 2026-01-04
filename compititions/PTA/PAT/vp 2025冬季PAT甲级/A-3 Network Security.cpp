#include <bits/stdc++.h>

using i64 = long long;

struct DSU{
  std::vector<int> f,sz;

  DSU(int n){
    f.resize(n+1);
    std::iota(f.begin(),f.end(),0);
    sz.assign(n+1,1);
  }

  int find(int x){
    if(f[x] != x){
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool merge(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv){
      return false;
    }
    if(fv < fu){
      std::swap(fu,fv);
    }
    sz[fu] += sz[fv];
    f[fv] = fu;
    return true;
  }
};

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n+1);
  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  for(int mi = 0; mi < m; mi++){
    int u,v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int max = 0;
  for(int i = 1; i <= n; i++){
    max = std::max(max,int(adj[i].size()));
  }

  bool isFirst = true;
  for(int i = 1; i <= n; i++){
    if(adj[i].size() == max && isFirst){
      std::cout << i;
      isFirst = false;
    }else if(adj[i].size() == max){
      std::cout << " " << i;
    }
  }
  std::cout << "\n";

  DSU dsu(n+1);
  for(int i = 1; i <= n; i++){
    if(a[i]){
      continue;
    }
    for(int j = 0; j < adj[i].size(); j++){
      if(a[adj[i][j]]){
        continue;
      }
      int findi = dsu.find(i);
      int findj = dsu.find(adj[i][j]);
      if(findi == findj){
        continue;
      }
      dsu.merge(findi,findj);
    }
  }

  std::map<int,std::vector<int>> map;

  for(int i = 1; i <= n; i++){
    if(a[i]){
      continue;
    }
    map[dsu.find(i)].push_back(i);
  }
  
  std::cout << map.size() << "\n";
  for(auto [u,v]:map){
    isFirst = true;
    for(int i = 0; i < v.size(); i++){
      if(isFirst){
        std::cout << v[i];
        isFirst = false;
      }else{
        std::cout << " " << v[i];
      }
    }
    std::cout << "\n";
  }
}