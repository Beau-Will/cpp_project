#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  auto get = [&](int x){
    int res = 1;
    for(int i = 2; i <= x/i; i++){
      if(x%i==0){
        res += i;
        if(i!=x/i){
          res += x/i;
        }
      }
    }
    return res;
  };

  int a,b;
  std::cin >> a >> b;

  int geta = get(a);
  int getb = get(b);

  std::cout << (geta==b&&getb==a?"YES\n":"NO\n");
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}