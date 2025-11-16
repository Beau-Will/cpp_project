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

    std::vector<int> x(n),y(n);
    for(int i = 0; i < n; i++){
      std::cin >> x[i] >> y[i];
    }

    i64 s1 = 0,s2 = 0;
    for(int i = 0; i < n; i++){
      s1 += x[i]*y[(i+1)%n];
      s2 += x[(i+1)%n]*y[i];
    }

    double ans = std::abs(s1-s2)/2.0;
    
    std::cout << std::fixed << std::setprecision(1) << ans << "\n";
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