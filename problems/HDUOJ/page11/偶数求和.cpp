#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m;
  while(std::cin >> n >> m){
    int sum = 0;
    for(int i = 1; i <= n; i++){
      sum += 2*i;
      
      if(i%m==0){
        std::cout << sum/m << " ";
        sum = 0;
      }
    }

    if(sum){
      std::cout << sum/(n%m);
    }

    std::cout << "\n";
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