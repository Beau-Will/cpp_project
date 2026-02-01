#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector g(n + 1, std::vector<int>(m + 1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      std::cin >> g[i][j];
    }
  }

  std::map<int, int> map;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(g[i][j]) map[g[i][j]]++;
    }
  }

  int cnt = 0, ans = 0;
  for(auto& [u, v] : map){
    int t = v / 2;
    if(t == 0){
      continue;
    }
    cnt += t;
    v -= t * 2;
    map[u + 1] += t;
    if(u >= k - 1){
      ans += t;
    }
  }

  std::cout << cnt << " " << ans << "\n";
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