#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  std::string s;
  std::cin >> s;

  if(s.find('s') == std::string::npos){
    if(s.size()&1){
      std::cout << (s.size()+1)/2 << "\n";
    }else{
      std::cout << (s.size()-1+1)/2+1 << "\n";
    }
    return;
  }

  int lastS = -1,ans = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 's'){
      lastS = i;
    }else{
      if(lastS == -1){
        ans++;
        s[i] = 's';
        lastS = i;
        continue;
      }

      int diff = i-lastS;
      if(i+diff >= s.size()){
        ans++;
        s[i] = 's';
        lastS = i;
        continue;
      }
      if(s[i+diff] == 'u'){
        s[i+diff] = 's';
        ans++;
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