#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  auto check = [&](int x){
    for(int i = 0; i < n; i++){
      if((x>>i&1) && (x>>(i+1)&1)){
        return false;
      }
    }
    return true;
  };

  std::vector<int> st;
  for(int i = 0; i < (1<<n); i++){
    if(check(i)){
      st.push_back(i);
    }
  }

  std::unordered_map<int,std::vector<int>> map;
  for(int i = 0; i < st.size(); i++){
    for(int j = 0; j < st.size(); j++){
      int x = st[i],y = st[j];
      if(((x&y)==0) && check(x|y)){
        map[x].push_back(y);
      }
    }
  }

  auto dp = std::vector(n+2,std::vector(n*n+1,std::vector<i64>(1<<n)));
  dp[0][0][0] = 1;

  for(int i = 1; i <= n+1; i++){
    for(int j = 0; j <= m; j++){
      for(int k = 0; k < st.size(); k++){
        int x = st[k];
        for(int l = 0; l < map[x].size(); l++){
          int y = map[x][l];

          int cnt1 = __builtin_popcount(x);
          if(j-cnt1 >= 0){
            dp[i][j][x] += dp[i-1][j-cnt1][y];
          }
        }
      }
    }
  }

  std::cout << dp[n+1][m][0] << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}