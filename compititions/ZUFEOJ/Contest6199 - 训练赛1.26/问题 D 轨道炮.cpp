#include <bits/stdc++.h>

using i64 = long long;

struct Node{
  i64 x,y,v;
  char dir;
};

void solve(){
  std::unordered_map<char,int> dx,dy;
  dx['R'] = 1;
  dx['L'] = -1;
  dx['U'] = 0;
  dx['D'] = 0;
  dy['R'] = 0;
  dy['L'] = 0;
  dy['U'] = 1;
  dy['D'] = -1;

  int n;
  std::cin >> n;

  std::vector<Node> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i].x >> a[i].y >> a[i].v >> a[i].dir;
  }

  int ans = 0;
  std::unordered_map<i64,int> cntX,cntY;
  for(int t = 0; t <= 1000; t++){
    cntX.clear();
    cntY.clear();
    for(int i = 0; i < n; i++){
      auto [x1,y1,v,dir] = a[i];
      i64 x2 = x1+t*v*dx[dir],y2 = y1+t*v*dy[dir];

      cntX[x2]++;
      cntY[y2]++;
    }
    int res = 0;
    for(const auto& [u,v]:cntX){
      res = std::max(res,v);
    }
    for(const auto& [u,v]:cntY){
      res = std::max(res,v);
    }

    ans = std::max(ans,res);
  }

  std::cout << ans << "\n";
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