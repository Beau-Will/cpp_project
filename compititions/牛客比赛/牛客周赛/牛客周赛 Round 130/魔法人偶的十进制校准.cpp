#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int a, b;
  std::cin >> a >> b;

  if(b == 1){
    std::cout << "1 9\n";
  }else if(b == 2){
    std::cout << "2 9\n";
  }else if(b == 3){
    std::cout << "1 3\n";
  }else if(b == 4){
    std::cout << "4 9\n";
  }else if(b == 5){
    std::cout <<  "5 9\n";
  }else if(b == 6){
    std::cout <<  "2 3\n";
  }else if(b == 7){
    std::cout <<  "7 9\n";
  }else if(b == 8){
    std::cout <<  "8 9\n";
  }else if(b == 0){
    if(a == 1){
      std::cout << "1 1000\n";
    }else{
      std::cout << "1 10\n";
    }
  }else{
    if(a & 1) std::cout << "10 11\n";
    else std::cout << "1 11\n";
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