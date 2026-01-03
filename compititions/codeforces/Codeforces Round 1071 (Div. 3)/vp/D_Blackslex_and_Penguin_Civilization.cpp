#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

/*
111111
011111
001111
101111
000111
010111
100111
110111
...
*/

void solve(){
  int n;
  std::cin >> n;

  for(int i = n; i >= 0; i--){
    std::cout << (1<<i)-1 << " ";

    if(i <= n-2){
      int t = (1<<i)-1;
      int diff = n-i;
      for(int j = 1; j < (1<<(diff-1)); j++){
        std::cout << t+(j<<(i+1)) << " ";
      }
    }
  }

  std::cout << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}