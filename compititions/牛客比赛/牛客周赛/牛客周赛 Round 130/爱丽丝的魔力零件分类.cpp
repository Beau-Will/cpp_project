#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

/*

  ***
   *
  
   *
  ***

  *
  **
  *

   *
  **
   *
*/

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(g[i][j] == '*'){
        bool isT = false;
        if((i + 1) < n && (j + 2) < n && g[i][j + 1] == '*' && g[i][j + 2] == '*' && g[i + 1][j + 1] == '*'){
          isT = true;
        }
        if((i + 1) < n && (j - 1) >= 0 && (j + 1) < n && g[i + 1][j - 1] == '*' && g[i + 1][j] == '*' && g[i + 1][j + 1] == '*'){
          isT = true;
        }
        if((i + 2) < n && (j + 1 < n) && g[i + 1][j] == '*' && g[i + 1][j + 1] == '*' && g[i + 2][j] == '*'){
          isT = true;
        }
        if((i + 2) < n && (j - 1) >= 0 && g[i + 1][j] == '*' && g[i + 1][j - 1] == '*' && g[i + 2][j] == '*'){
          isT = true;
        }
        std::cout << (isT ? "T\n" : "L\n");
        return;
      }
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}