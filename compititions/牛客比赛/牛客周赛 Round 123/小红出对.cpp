#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<bool>> vis(200001,std::vector<bool>(4,false));
  std::vector<std::vector<int>> a(200001);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int n;
    char c;
    std::cin >> n >> c;

    if(!vis[n][c-'A']){
      vis[n][c-'A'] = true;
      a[n].push_back(i+1);
    }
  }
  
  for(int i = 1; i <= 200000; i++){
    ans += a[i].size()/2*2;
  }
  std::cout << ans << "\n";
  
  for(int i = 1; i <= 200000; i++){
    for(int j = 0; j+1 < a[i].size(); j+=2){
      std::cout << a[i][j] << " " << a[i][j+1] << "\n";
    }
  }
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