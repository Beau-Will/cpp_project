#include <iostream>
#include <vector>
#include <queue>
#include <array>

void solve(){
  int n;
  std::cin >> n;

  if(n % 4 == 0){
    std::cout << n << "\n";
  }else if(n % 4 == 1){
    std::cout << 0 << "\n";
  }else if(n % 4 == 2){
    std::cout << n+1 << "\n";
  }else{
    std::cout << 1 << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // 打表
  // for(int n = 1; n <= 100; n++){
  //   std::vector<std::vector<std::array<int,2>>> adj(n+1);
  //   for(int i = 1; i <= n; i++){
  //     for(int j = 1; j <= n; j++){
  //       if(i == j){
  //         continue;
  //       }
  //       adj[i].push_back({j,i^j});
  //     }
  //   }

  //   std::vector<int> dist(n+1,2E9+1);
  //   std::vector<bool> vis(n+1);
  //   auto dijkstra = [&](){
  //     using Node = std::array<int,2>;
  //     std::priority_queue<Node,std::vector<Node>,std::greater<>> heap;
  //     heap.push({0,1});
  //     dist[1] = 0;

  //     while(heap.size()){
  //       auto [distance,u] = heap.top();
  //       heap.pop();

  //       if(vis[u]){
  //         continue;
  //       }
  //       vis[u] = true;

  //       for(const auto& [v,w]:adj[u]){
  //         if(dist[u]+w < dist[v]){
  //           dist[v] = dist[u]+w;
  //           heap.push({dist[v],v});
  //         }
  //       }
  //     }
  //   };

  //   dijkstra();

  //   int ans = 0;
  //   for(int i = 1; i <= n; i++){
  //     ans ^= dist[i];
  //   }
  //   std::cout << ans << " \n"[n%10==0];
  // }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}