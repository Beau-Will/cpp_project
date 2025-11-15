#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  while(std::cin >> n){
    int sum = 0,min = 101,max = -1,x;
    for(int i = 0; i < n; i++){
      std::cin >> x;
      sum += x;
      min = std::min(min,x);
      max = std::max(max,x);
    }
    double ans = 1.*(sum-min-max)/(n-2);
    std::cout << std::fixed << std::setprecision(2) << ans << "\n";
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