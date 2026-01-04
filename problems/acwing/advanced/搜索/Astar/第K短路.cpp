#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int,int>>> adj(n+1),radj(n+1);

  for(int i = 0; i < m; i++){
    int u,v,w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v,w});
    radj[v].push_back({u,w});
  }

  int S,T,K;
  std::cin >> S >> T >> K;
  if(S == T){
    K++;
  }

  std::vector<int> dist(n+1,inf1);
  std::vector<bool> vis(n+1);

  auto dijkstra = [&](){
    using PII = std::pair<int,int>;
    std::priority_queue<PII,std::vector<PII>,std::greater<PII>> heap;
    dist[T] = 0;
    heap.push({0,T});

    while(heap.size()){
      auto [distance,u] = heap.top();
      heap.pop();

      if(vis[u]){
        continue;
      }
      vis[u] = true;

      for(auto [v,w]:radj[u]){
        if(dist[u]+w < dist[v]){
          dist[v] = dist[u]+w;
          heap.push({dist[v],v});
        }
      }
    }
  };

  dijkstra();

  auto Astar = [&](){
    using Node = std::tuple<int,int,int>;
    std::priority_queue<Node,std::vector<Node>,std::greater<Node>> heap;

    std::vector<int> cnt(n+1);

    heap.push({dist[S],0,S});
    while(heap.size()){
      auto [_,distance,u] = heap.top();
      heap.pop();

      cnt[u]++;
      if(cnt[T] == K){
        return distance;
      }
      for(auto [v,w]:adj[u]){
        if(cnt[v] < K){
          heap.push({distance+w+dist[v],distance+w,v});
        }
      }
    }
    return -1;
  };

  std::cout << Astar() << "\n";
}

int main(){
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