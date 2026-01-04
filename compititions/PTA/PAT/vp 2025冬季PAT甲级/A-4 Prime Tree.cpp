#include <bits/stdc++.h>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n+1);
  int root = -1;
  for(int i = 1; i <= n; i++){
    int fa;
    std::cin >> fa;
    if(fa == 0){
        root = i;
    }
    adj[fa].push_back(i);
  }

  std::vector<int> dep(n+1),son(n+1);
  dep[root] = 1;

  auto dfs = [&](auto &&self,int u) ->void {
    for(auto v:adj[u]){
      dep[v] = dep[u]+1;
      self(self,v);
      son[u] += son[v]+1;
    }
  };
  
  dfs(dfs,root);

  bool isPrimeTree = true;

  auto isPrime = [&](int x){
    if(x < 2){
      return false;
    }
    for(int i = 2; i <= x/i; i++){
      if(x % i == 0){
        return false;
      }
    }
    return true;
  };

  for(int i = 1; i <= n; i++){
    std::cout << i << " " << dep[i] << " " << son[i] << "\n";
    bool isPrime1 = isPrime(dep[i]);
    bool isPrime2 = isPrime(son[i]);
    if((isPrime1&&!isPrime2) || (!isPrime1&&isPrime2)){
      isPrimeTree = false;
    }
  }
  std::cout << (isPrimeTree?1:0) << "\n";
}