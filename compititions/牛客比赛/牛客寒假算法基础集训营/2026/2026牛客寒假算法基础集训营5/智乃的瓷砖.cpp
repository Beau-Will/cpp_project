#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  // std::vector g(n, std::vector<char>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if((i & 1) == (j & 1)){
        std::cout << "/";
      }else{
        std::cout << "\\";
      }
    }
    std::cout << "\n";
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