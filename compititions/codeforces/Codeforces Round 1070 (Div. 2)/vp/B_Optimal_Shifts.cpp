#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

constexpr int N = 2E5;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::string t = s+s;
  
  int ans = 0,cnt0 = 0;
  for(int i = 0; i < n*2; i++){
    if(t[i] == '0'){
      cnt0++;
    }else{
      ans = std::max(ans,cnt0);
      cnt0 = 0;
    }
  }
  ans = std::max(ans,cnt0);
  
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