#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  while(std::cin >> n){
    if(n==0){
      break;
    }

    int big = 1,small1 = 0,small2 = 0,small3 = 0;
    for(int i = 2; i <= n; i++){
      big += small3;
      small3 = small2;
      small2 = small1;
      small1 = big;
    }
    std::cout << big+small1+small2+small3 << "\n";
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