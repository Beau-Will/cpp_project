#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m;
  while(std::cin >> n >> m){
    int abs_max = 0,row = 1,col = 1,x;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        std::cin >> x;
        if(std::abs(x) > std::abs(abs_max)){
          abs_max = x;
          row = i,col = j;
        }
      }
    }

    std::cout << row << " " << col << " " << abs_max << "\n";
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