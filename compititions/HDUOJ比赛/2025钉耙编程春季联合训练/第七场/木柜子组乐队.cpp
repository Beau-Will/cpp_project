#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  std::vector<int> a(5);
  for(int i = 0; i < 5; ++i){
    std::cin >> a[i];
  }
  i64 ans = 1;
  ans *= 1LL*a[0]*a[1]*a[2];
  
  if(a[4]!=0){
    ans *= ((a[3]+a[4]-1)+a[4])*a[3]/2;
  }else{
    ans *= a[3]*(a[3]-1)/2;
  }
  
  // if(a[4]!=0) ans *= a[4];

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}