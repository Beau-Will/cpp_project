#include <iostream>
#include <vector>
#include <queue>

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  auto bfs = [&](){
    std::vector<int> dist(n + 1, inf);
    std::vector<bool> vis(n + 1);
    std::queue<int> q;
    q.push(n);
    vis[n] = true;
    dist[n] = 0;

    while(q.size()){
      auto u = q.front();
      q.pop();

      if(u == 0){
        return dist[u];
      }

      if(u - 8 >= 0 && !vis[u - 8]){
        dist[u - 8] = dist[u] + 1;
        vis[u - 8] = true;
        q.push(u - 8);
      }

      if(u - 6 >= 0 && !vis[u - 6]){
        dist[u - 6] = dist[u] + 1;
        vis[u - 6] = true;
        q.push(u - 6);
      }
    }

    return -1;
  };

  std::cout << bfs() << "\n";

  return 0;
}