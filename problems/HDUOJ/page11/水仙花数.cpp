#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int l,r;
  while(std::cin >> l >> r){
    std::vector<int> ans;
    for(int i = l; i <= r; i++){
      if(i==std::pow(i/100,3)+std::pow(i/10%10,3)+std::pow(i%10,3)){
        ans.push_back(i);
      }
    }
    if(ans.size()==0){
      std::cout << "no\n";
    }else{
      for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " \n"[i+1==ans.size()];
      }
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