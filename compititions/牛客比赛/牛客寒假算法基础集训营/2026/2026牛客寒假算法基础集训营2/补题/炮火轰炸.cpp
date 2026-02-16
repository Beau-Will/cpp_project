#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr std::array<std::array<int, 2>, 4> d = {{
  {-1, 0},
  {0, -1},
  {1, 0},
  {0, 1}
}};

void solve(){
  int n, q;
  std::cin >> n >> q;

  std::vector set(1'000'002, std::set<int>());
  for(int i = 0; i < n; i++){
    int x, y;
    std::cin >> x >> y;
    set[x].insert(y);
  }

  std::vector map(1'000'002, std::map<int, int>());
  std::vector mx(1'000'002, std::set<int>()), my = mx;

  auto in = [&](int x, int y){
    auto itx = mx[x].lower_bound(y);
    auto ity = my[y].lower_bound(x);
    if(itx == mx[x].end() || ity == my[y].end()){
      return 0;
    }
    return std::min(map[x][*itx], map[*ity][y]);
  };

  std::function<void(int, int, int)> dfs = [&](int x, int y, int cnt){
    map[x][y] = cnt;
    mx[x].insert(y);
    my[y].insert(x);
    for(auto& [dx, dy] : d){
      int u = x + dx, v = y + dy;
      if(u < 0 || v < 0){
        continue;
      }
      if(set[u].count(v)){
        continue;
      }
      if(map[u].count(v)){
        continue;
      }
      int t = 0;
      for(int ddx = -1; ddx <= 1; ddx++){
        for(int ddy = -1; ddy <= 1; ddy++){
          if(u + ddx >= 0){
            t |= set[u + ddx].count(v + ddy);
          }
        }
      }
      if(t){
        dfs(u, v, cnt);
      }
    }
  };

  for(int x = 1; x <= 1'000'000; x++){
    for(const auto& y : set[x]){
      if(in(x, y)){
        continue;
      }
      for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
          int u = x + dx, v = y + dy;
          if(u < 0 || v < 0){
            continue;
          }
          if(set[u].count(v)){
            continue;
          }
          if(map[u].count(v)){
            continue;
          }
          if(std::min(dx, dy) >= 0){
            dfs(u, v, 1);
          }else{
            dfs(u, v, 0);
          }
        }
      }
    }
  }

  for(int qi = 0; qi < q; qi++){
    int x, y;
    std::cin >> x >> y;

    std::cout << (in(x, y) ? "YES\n" : "NO\n");
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}