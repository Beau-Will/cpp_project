#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<std::string> t(2);
  for(int i = 0; i < n; i++){
    if(i & 1){
      t[0] += '1';
      t[1] += '0';
    }else{
      t[0] += '0';
      t[1] += '1';
    }
  }

  std::vector<std::string> tmp(2);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      if(s[j] != t[i][j]){
        tmp[i] += s[j];
      }
    }
  }

  std::vector<int> dp0(2), dp1(2);
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < tmp[i].size(); j++){
      int cur = tmp[i][j] ^ 48;
      if(cur){
        if(dp0[i]){
          dp0[i]--;
          dp1[i]++;
        }else{
          dp1[i]++;
        }
      }else{
        if(dp1[i]){
          dp1[i]--;
          dp0[i]++;
        }else{
          dp0[i]++;
        }
      }
    }
  }

  int ans = std::min(dp0.front() + dp1.front(), dp0.back() + dp1.back());
  std::cout << ans << "\n";
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