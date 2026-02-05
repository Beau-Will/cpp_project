#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for(int i = 0; i < n; i++){
    std::cin >> g[i];
  }

  int cnt0 = 0, cnt1 = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '0'){
        cnt0++;
      }else{
        cnt1++;
      }
    }
  }

  std::vector<std::string> ans(n, std::string(m, 'Y'));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '0'){
        if(cnt0 < 2){
          ans[i][j] = 'N';
        }
      }else{
        if(cnt1 < 2){
          ans[i][j] = 'N';
        }
      }
    }
  }

  for(int i = 0; i < n; i++){
    std::cout << ans[i] << "\n";
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