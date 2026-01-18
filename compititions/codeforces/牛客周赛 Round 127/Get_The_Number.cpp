#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int a,b,c;
  std::cin >> a >> b >> c;

  if(c == a+b || c == a-b || c == a*b || a % b == 0 && c == a/b){
    std::cout << "YES\n";
  }else{
    std::cout << "NO\n";
  }
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