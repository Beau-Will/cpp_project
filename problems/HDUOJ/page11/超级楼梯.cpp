#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> f(41);

void solve() {
  int n;
  std::cin >> n;

  std::cout << f[n] << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  f[1] = 1;
  for(int i = 2; i <= 40; i++){
    f[i] += f[i-1]+f[i-2];
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}