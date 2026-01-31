#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n,m,q;
  std::cin >> n >> m >> q;

  std::vector<std::vector<int>> a(n,std::vector<int>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      std::cin >> a[i][j];
    }
  }
  
  std::vector<int> query(q);
  for(int i = 0; i < q; ++i){
    std::cin >> query[i];
  }

  std::vector<int> dx = {0,0,-1,1};
  std::vector<int> dy = {-1,1,0,0};

  std::vector<std::vector<int>> dist(n,std::vector<int>(m,inf3));
  std::vector<std::vector<bool>> vis(n,std::vector<bool>(m));

  auto dijkstra = [&](){
    std::priority_queue<std::array<int,3>,std::vector<std::array<int,3>>,std::greater<std::array<int,3>>> pq;
    
    for(int i = 0; i < m; ++i){
      dist[0][i] = a[0][i];
      pq.push({dist[0][i],0,i});
      vis[0][i] = true;
    }

    while(!pq.empty()){
      auto [w,x,y] = pq.top();
      pq.pop();

      for(int i = 0; i < 4; ++i){
        int u = x+dx[i],v = y+dy[i];
        if(u<0||u>=n||v<0||v>=m||vis[u][v]){
          continue;
        }
        if(std::max(w,a[u][v]) < dist[u][v]){
          dist[u][v] = std::max(w,a[u][v]);
          vis[u][v] = true;
          pq.push({dist[u][v],u,v});
        }
      }
    }
  };

  dijkstra();

  std::vector<int> res;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      res.push_back(dist[i][j]);
    }
  }

  std::sort(all(res));
  
  for(int i = 0; i < q; ++i){
    std::cout << std::upper_bound(all(res),query[i])-res.begin() << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}