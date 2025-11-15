#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int t;
  while(std::cin >> t){
    if(t>100){
      std::cout << "Score is error!\n";
    }else if(t>=90){
      std::cout << "A\n";
    }else if(t>=80){
      std::cout << "B\n";
    }else if(t>=70){
      std::cout << "C\n";
    }else if(t>=60){
      std::cout << "D\n";
    }else if(t>=0){
      std::cout << "E\n";
    }else{
      std::cout << "Score is error!\n";
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}