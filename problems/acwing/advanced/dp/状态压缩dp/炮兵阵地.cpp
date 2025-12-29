#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+1);
  
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < m; j++){
      char c;
      std::cin >> c;
      if(c=='H'){
        a[i] += 1<<j;
      }
    }
  }

  auto check = [&](int x){
    for(int i = 0; i < m; i++){
      if((x>>i&1) && ((x>>(i+1)&1) | (x>>(i+2)&1))){
        return false;
      }
    }
    return true;
  };

  std::vector<int> st;
  for(int i = 0; i < (1<<m); i++){
    if(check(i)){
      st.push_back(i);
    }
  }

  auto dp = std::vector(2,std::vector(1<<m,std::vector(1<<m,0)));

  for(int i = 1; i <= n+2; i++){
    for(int j = 0; j < st.size(); j++){
      int x = st[j];
      for(int k = 0; k < st.size(); k++){
        int y = st[k];
        for(int l = 0; l < st.size(); l++){
          int z = st[l];

          if((x & y) || (x & z) || (y & z)){
            continue;
          }
          if((x & a[i]) || (y & a[i-1])){
            continue;
          }

          dp[i&1][y][x] = std::max(dp[i&1][y][x],dp[(i-1)&1][z][y]+__builtin_popcount(x));
        }
      }
    }
  }

  std::cout << dp[(n+2)&1][0][0];
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