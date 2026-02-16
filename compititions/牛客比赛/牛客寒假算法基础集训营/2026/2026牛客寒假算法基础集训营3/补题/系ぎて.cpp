#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr std::array dx = {0, 0, -1, 1};
constexpr std::array dy = {-1, 1, 0, 0};

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  std::vector<std::array<int, 2>> p1, p2;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '1'){
        p1.push_back({i, j});
      }else if(g[i][j] == '2'){
        p2.push_back({i, j});
      }
    }
  }

  std::map<std::array<int, 2>, std::array<int, 2>> prev;
  std::vector dist(n, std::vector<int>(m, inf1));
  std::queue<std::array<int, 2>> q;
  bool isok = false;
  int sx = p1[0][0], sy = p1[0][1], ex = p1[1][0], ey = p1[1][1];
  dist[sx][sy] = 0;
  q.push({sx, sy});
  
  while(q.size()){
    auto [x, y] = q.front();
    q.pop();

    if(x == ex && y == ey){
      isok = true;
      break;
    }

    for(int i = 0; i < 4; i++){
      int u = x + dx[i], v = y + dy[i];
      if(u < 0 || u >= n || v < 0 || v >= m || dist[u][v] != inf1 || g[u][v] == '2'){
        continue;
      }
      dist[u][v] = dist[x][y] + 1;
      prev[{u, v}] = {x, y};
      q.push({u, v});
    }
  }

  std::vector vis(n, std::vector<bool>(m));
  if(isok){
    vis[ex][ey] = true;
    while(!(ex == sx && ey == sy)){
      auto [tx, ty] = prev[{ex, ey}];
      ex = tx, ey = ty;
      vis[ex][ey] = true;
    }
  }else{
    std::cout << "NO\n";
    return;
  }

  while(q.size()){
    q.pop();
  }
  sx = p2[0][0], sy = p2[0][1], ex = p2[1][0], ey = p2[1][1];
  isok = false;
  q.push({sx, sy});

  while(q.size()){
    auto [x, y] = q.front();
    q.pop();

    if(x == ex && y == ey){
      isok = true;
      break;
    }

    for(int i = 0; i < 4; i++){
      int u = x + dx[i], v = y + dy[i];
      if(u < 0 || u >= n || v < 0 || v >= m || vis[u][v]){
        continue;
      }
      vis[u][v] = true;
      q.push({u, v});
    }
  }

  if(isok){
    std::cout << "YES\n";
    return;
  }

  prev.clear();
  std::fill(dist.begin(), dist.end(), std::vector<int>(m, inf1));
  while(q.size()){
    q.pop();
  }
  isok = false;
  dist[sx][sy] = 0;
  q.push({sx, sy});

  while(q.size()){
    auto [x, y] = q.front();
    q.pop();

    if(x == ex && y == ey){
      isok = true;
      break;
    }

    for(int i = 0; i < 4; i++){
      int u = x + dx[i], v = y + dy[i];
      if(u < 0 || u >= n || v < 0 || v >= m || dist[u][v] != inf1|| g[u][v] == '1'){
        continue;
      }
      dist[u][v] = dist[x][y] + 1;
      prev[{u, v}] = {x, y};
      q.push({u, v});
    }
  }

  if(isok){
    std::fill(vis.begin(), vis.end(), std::vector<bool>(m));
    vis[ex][ey] = true;
    while(!(ex == sx && ey == sy)){
      auto [tx, ty] = prev[{ex, ey}];
      ex = tx, ey = ty;
      vis[ex][ey] = true;
    }
  }else{
    std::cout << "NO\n";
    return;
  }

  while(q.size()){
    q.pop();
  }
  sx = p1[0][0], sy = p1[0][1], ex = p1[1][0], ey = p1[1][1];
  isok = false;
  q.push({sx, sy});

  while(q.size()){
    auto [x, y] = q.front();
    q.pop();

    if(x == ex && y == ey){
      isok = true;
      break;
    }

    for(int i = 0; i < 4; i++){
      int u = x + dx[i], v = y + dy[i];
      if(u < 0 || u >= n || v < 0 || v >= m || vis[u][v]){
        continue;
      }
      vis[u][v] = true;
      q.push({u, v});
    }
  }

  std::cout << (isok ? "YES\n" : "NO\n");
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}