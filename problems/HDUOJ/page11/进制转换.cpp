#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<char> a;
  for(int i = 0; i < 16; i++){
    if(i<10){
      a.push_back('0'+i);
    }else{
      a.push_back('A'+i-10);
    }
  } 

  int n,k;
  while(std::cin >> n >> k){
    std::vector<char> ans;
    int op = n<0;

    n = std::abs(n);
    while(n){
      ans.push_back(a[n%k]);
      n/=k;
    }

    if(op){
      std::cout << "-";
    }
    for(int i = ans.size()-1; i >= 0; i--){
      std::cout << ans[i];
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