#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <array>
#include <algorithm>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n;
  std::cin >> n;
  
  std::vector<std::vector<int>> adj(n + 1);
  std::vector p(n, std::array<int,2>{});
  std::vector<int> all;
  int rt;
  for(int i = 0; i < n; i++){
    int u,v;
    std::cin >> u >> v;
    p[i] = {u, v};
    if(v == -1){
      rt = u;
      all.push_back(u);
      continue;
    }
    all.push_back(u);
    all.push_back(v);
  }
  
  std::sort(all.begin(), all.end());
  all.erase(std::unique(all.begin(), all.end()), all.end());
  
  auto query = [&](int x){
    return std::lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };
  
  for(int i = 0; i < n; i++){
    auto [u, v] = p[i];
    if(v == -1){
      continue;
    }
    
    int idxu = query(u);
    int idxv = query(v);
    adj[idxu].push_back(idxv);
    adj[idxv].push_back(idxu);
  }
  
  rt = query(rt);
  
  int log = std::log2(n);
  
  std::vector f(log + 1, std::vector<int>(n + 1));
  std::vector<int> par(n + 1), dep(n + 1);
  dep[rt] = 1;
  
  std::function<void(int)> dfs = [&](int u) {
  	f[0][u] = par[u];
  	for (int i = 1; i <= log; i += 1) {
  		f[i][u] = f[i - 1][f[i - 1][u]];
  	}
  	for (const auto& v : adj[u]) {
  		if (v == par[u]) {
  			continue;
  		}
  		par[v] = u;
  		dep[v] = dep[u] + 1;
  		dfs(v);
  	}
  };
  
  dfs(rt);
  
  auto lca = [&](int u, int v) {
  	if (dep[u] < dep[v]) std::swap(u, v);
  	for (int i = log; i >= 0; i -= 1) {
  		if (dep[f[i][u]] >= dep[v]) {
  			u = f[i][u];
  		}
  	}
  	if (u == v) return u;
  	for (int i = log; i >= 0; i -= 1) {
  		if (f[i][u] != f[i][v]) {
  			u = f[i][u], v = f[i][v];
  		}
  	};
  	return f[0][u];
  };
  
  int m;
  std::cin >> m;
  
  for(int mi = 0; mi < m; mi++){
    int u,v;
    std::cin >> u >> v;
    
    int idxu = query(u);
    int idxv = query(v);
    
    int uvlca = lca(idxu, idxv);
    if(idxu == uvlca){
      std::cout << "1\n";
    }else if(idxv == uvlca){
      std::cout << "2\n";
    }else{
      std::cout << "0\n";
    }
  }
}