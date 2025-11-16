#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<double> v(3);
  for(int j = 0; j < 3; j++){
    std::cin >> v[j];
  }

  std::sort(v.begin(),v.end());

  std::cout << (v[0]+v[1]>v[2]?"YES\n":"NO\n");
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