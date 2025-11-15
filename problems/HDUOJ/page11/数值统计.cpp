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

    int ans1 = 0,ans2 = 0,ans3 = 0;
    double x;

    for(int i = 0; i < n; i++){
      std::cin >> x;
      if(x==0){
        ans2++;
      }else if(x<0){
        ans1++;
      }else{
        ans3++;
      }
    }
    
    std::cout << ans1 << " " <<  ans2 << " " << ans3 << "\n";
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