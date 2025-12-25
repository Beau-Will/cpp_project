#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> node(n+1);
  std::vector<std::map<int,int>> map(n+1);
  std::vector<std::vector<int>> id(n+1);

  int cnt = 0;

  for(int i = 1; i <= n; i++){
    int xi,yi;
    std::cin >> xi >> yi;

    int t = node[xi];
    if(map[t].count(yi)){
      node[i] = map[t][yi];
    }else{
      ++cnt;
      map[t][yi] = cnt;
      node[i] = cnt;
    }
    id[node[i]].push_back(i);
  }

  auto dfs = [&](auto &&self,int u)->void {
    if(u!=0){
      std::sort(id[u].begin(),id[u].end());
      for(int i = 0; i < id[u].size(); i++){
        std::cout << id[u][i] << " ";
      }
    }
    for(auto [x,y]:map[u]){
      self(self,y);
    }
  };

  dfs(dfs,0);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}