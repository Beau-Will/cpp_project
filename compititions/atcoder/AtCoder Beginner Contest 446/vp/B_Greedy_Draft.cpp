#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> vis(m + 1);
  for(int i = 0; i < n; i++){
    int l;
    std::cin >> l;

    int ans = 0;
    for(int j = 0; j < l; j++){
      int x;
      std::cin >> x;

      if(!vis[x] && !ans){
        ans = x;
        vis[x] = true;
      }
    }

    std::cout << ans << "\n";
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