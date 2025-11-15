#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  auto get = [&](int n){
    int res = 0;
    res += n/100;
    n %= 100;
    res += n/50;
    n %= 50;
    res += n/10;
    n %= 10;
    res += n/5;
    n %= 5;
    res += n/2;
    n %= 2;
    res += n/1;
    n %= 1;
    return res;
  };

  int n;
  while(std::cin >> n){
    if(n==0){
      break;
    }

    int ans = 0,x;
    for(int i = 0; i < n; i++){
      std::cin >> x;
      ans += get(x);
    }

    std::cout << ans << "\n";
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