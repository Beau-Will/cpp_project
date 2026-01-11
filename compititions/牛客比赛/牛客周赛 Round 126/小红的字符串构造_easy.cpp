#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::vector<std::string> s(n);
  for(int i = 0; i < n; i++){
    std::cin >> s[i];
  }

  std::sort(s.begin(),s.end());

  for(int i = k; i < n; i++){
    if(s[i] == s[k-1]){
      std::cout << "-1\n";
      return;
    }else{
      break;
    }
  }
  
  std::cout << s[k-1] << "\n";
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
}