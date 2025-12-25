#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m,k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> a(n,std::vector<int>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      std::cin >> a[i][j];
    }
  }

  std::vector<int> b(k);
  for(int i = 0; i < k; i++){
    std::cin >> b[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    int cnt = 0;
    for(int j = 0; j < m; j++){
      for(int l = 0; l < k; l++){
        if(a[i][j]==b[l]){
          cnt++;
        }
      }
    }
    ans = std::max(ans,cnt);
  }

  std::cout << ans << "\n";
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