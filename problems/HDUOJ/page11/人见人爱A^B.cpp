#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

auto quick_power = [](int a,int b,int p){
  int res = 1;
  for(; b; b>>=1, a = 1LL*a*a%p){
    if(b&1){
      res = 1LL*res*a%p;
    }
  }
  return res;
};

void solve() {
  int a,b;
  while(std::cin >> a >> b){
    if(a==0 && b==0){
      break;
    }
    std::cout << quick_power(a, b, 1000) << "\n";
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