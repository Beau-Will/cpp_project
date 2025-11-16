#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<std::vector<int>> v(31,std::vector<int>(31));
  v[1][1] = 1;
  for(int i = 2; i <= 30; i++){
    for(int j = 1; j <= i; j++){
      v[i][j] = v[i-1][j-1]+v[i-1][j];
    }
  }

  int n;
  while(std::cin >> n){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= i; j++){
        std::cout << v[i][j] << " \n"[j==i];
      }
    }

    std::cout << "\n";
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