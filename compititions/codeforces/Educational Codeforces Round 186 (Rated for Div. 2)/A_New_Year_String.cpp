#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  bool flag1 = false,flag2 = false;
  for(int i = 0; i+3 < n; i++){
    if(s.substr(i,4) == "2026"){
      flag1 = true;
    }
    if(s.substr(i,4) == "2025"){
      flag2 = true;
    }
  }

  if(flag1){
    std::cout << "0\n";
    return;
  }

  if(!flag1 && flag2){
    std::cout << "1\n";
    return;
  }

  std::cout << "0\n";
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