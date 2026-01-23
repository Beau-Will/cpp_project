#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using i64 = long long;
using pii = std::pair<int,int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,m;
  std::cin >> n >> m;

  std::vector<std::vector<pii>> adj1(n),adj2(n);
  for(int i = 0; i < m; i++){
    int u,v,w;
    std::cin >> u >> v >> w;
    u--,v--;

    adj1[u].push_back({v,w});
    adj2[v].push_back({u,w});
  }

  std::vector<bool> vis1(n),vis2(n);
  std::vector<int> dist1(n,1E9),dist2(n,1E9);
  auto dijkstra1 = [&](){
    std::priority_queue<pii,std::vector<pii>,std::greater<>> heap;
    dist1[0] = 0;
    heap.push({0,0});
    
    while(heap.size()){
      auto [distance,u] = heap.top();
      heap.pop();

      if(vis1[u]){
        continue;
      }
      vis1[u] = true;

      for(const auto& [v,w]:adj1[u]){
        if(distance+w < dist1[v]){
          dist1[v] = distance+w;
          heap.push({dist1[v],v});
        }
      }
    }
  };

  dijkstra1();

  auto dijkstra2 = [&](){
    std::priority_queue<pii,std::vector<pii>,std::greater<>> heap;

    dist2[0] = 0;
    heap.push({0,0});

    while(heap.size()){
      auto [distance,u] = heap.top();
      heap.pop();

      if(vis2[u]){
        continue;
      }
      vis2[u] = true;

      for(const auto& [v,w]:adj2[u]){
        if(distance+w < dist2[v]){
          dist2[v] = distance+w;
          heap.push({dist2[v],v});
        }
      }
    }
  };

  dijkstra2();

  int ans = 0;
  for(int i = 1; i < n; i++){
    ans += dist1[i]+dist2[i];
  }

  std::cout << ans << "\n";
}