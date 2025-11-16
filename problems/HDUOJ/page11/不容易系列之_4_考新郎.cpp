#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<i64> f(21);

auto fac = [](int n){
  i64 res = 1;
  for(int i = 1; i <= n; i++){
    res *= i;
  }
  return res;
};

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::cout << fac(n)/fac(n-m)/fac(m)*f[m] << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[2] = 1;
  f[3] = 2;
  for(int i = 4; i <= 20; i++){
    f[i] = (i-1)*(f[i-1]+f[i-2]);
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}