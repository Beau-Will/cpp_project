#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<i64> f(21),g(21);

void solve() {
  int n;
  std::cin >> n;

  std::cout << std::fixed << std::setprecision(2) << 100.*f[n]/g[n] << "%\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[1] = 0;
  f[2] = 1;
  for(i64 i = 3; i <= 20; i++){
    f[i] = (i-1)*(f[i-1]+f[i-2]);
  }

  g[0] = 1;
  for(i64 i = 1; i <= 20; i++){
    g[i] = g[i-1]*i;
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}