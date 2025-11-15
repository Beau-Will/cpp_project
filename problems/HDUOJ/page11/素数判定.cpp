#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  auto f = [&](int n){
    return n*n+n+41;
  };

  auto is_prime = [&](int n){
    if(n<2){
      return false;
    }
    for(int i = 2; i <= n/i; i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  };

  int l,r;
  while(std::cin >> l >> r){
    if(l==0 && r==0){
      break;
    }

    bool isok = true;
    for(int i = l; i <= r; i++){
      if(!is_prime(f(i))){
        isok = false;
        break;
      }
    }

    std::cout << (isok?"OK\n":"Sorry\n");
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