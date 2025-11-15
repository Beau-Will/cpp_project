#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int l,r;
  while(std::cin >> l >> r){
    if(l>r){
      std::swap(l,r);
    }
    i64 ans1 = 0,ans2 = 0;
    for(int i = l; i <= r; i++){
      i64 t = 1LL*i*i;
      if(t&1){
        t *= i;
        ans2 += t;
      }else{
        ans1 += t;
      }
    }
    std::cout << ans1 << " " << ans2 << "\n";
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