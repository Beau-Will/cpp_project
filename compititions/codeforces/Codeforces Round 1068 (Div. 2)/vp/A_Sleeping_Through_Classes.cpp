#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  std::vector<bool> canSleep(n,true);
  int ans = 0;
  
  for(int i = 0; i < n; i++){
    if(s[i]=='0' && canSleep[i]){
      ans++;
    }else if(s[i] == '1'){
      for(int j = i+1; j < std::min(n,i+k+1); j++){
        canSleep[j] = false;
      }
    }
  }

  std::cout << ans << "\n";
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