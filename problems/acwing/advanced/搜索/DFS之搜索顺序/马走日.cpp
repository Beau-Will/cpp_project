#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

void solve() {
  int n,m,sx,sy;
  std::cin >> n >> m >> sx >> sy;

  int ans = 0;

  auto vis = std::vector(n,std::vector<bool>(m));

  std::vector<int> dx = {-2,-1,1,2,2,1,-1,-2};
  std::vector<int> dy = {1,2,2,1,-1,-2,-2,-1};

  auto dfs = [&](auto &&self,int x,int y,int cnt)->void {
    if(cnt==n*m){
      ++ans;
      return;
    }
    
    vis[x][y] = true;

    for(int i = 0; i < dx.size(); ++i){
      int u = x+dx[i],v = y+dy[i];
      if(u<0||u>=n||v<0||v>=m||vis[u][v]){
        continue;
      }
      self(self,u,v,cnt+1);
    }

    vis[x][y] = false;
  };

  dfs(dfs,sx,sy,1);

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}