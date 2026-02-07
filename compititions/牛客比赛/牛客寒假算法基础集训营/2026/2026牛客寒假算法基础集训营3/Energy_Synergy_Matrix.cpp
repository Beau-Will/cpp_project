#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 n;
  std::cin >> n;

  if(n == 1){
    std::cout << "0\n";
  }else if(n == 2){
    std::cout << "1\n";
  }else if(n == 3){
    std::cout << "2\n";
  }else if(n == 4){
    std::cout << "3\n";
  }else{
    if(n % 2 == 1){
      std::cout << n << "\n";
    }else{
      std::cout << n - 1 << "\n";
    }
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