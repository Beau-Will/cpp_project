#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector g(n + 1, std::vector<char>(m + 1, '0'));

  for(int i = 2; i <= n; i += 3){
    for(int j = 2; j <= m; j += 3){
      g[i][j] = '1';
    }
  }

  if(n % 3 == 1){
    for(int j = 2; j <= m; j += 3){
      g[n][j] = '1';
    }
    if(m % 3 == 1){
      g[n][m] = '1';
    }
  }

  if(m % 3 == 1){
    for(int i = 2; i <= n; i += 3){
      g[i][m] = '1';
    }
    if(n % 3 == 1){
      g[n][m] = '1';
    }
  }

  int max = n * m - ((n + 2) / 3) * ((m + 2) / 3);

  if(k > max){
    std::cout << "-1\n";
    return;
  }

  int t = max - k;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(t == 0){
        break;
      }
      if(g[i][j] == '0'){
        g[i][j] = '1';
        t--;
      }
      if(t == 0){
        break;
      }
    }
    if(t == 0){
      break;
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      std::cout << g[i][j];
    }
    std::cout << "\n";
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