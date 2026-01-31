#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<int> a(13),b(13);

  for(int i = 0; i < 13; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < 13; i++){
    std::cin >> b[i];
  }

  int ans = 0;
  for(int i = 0; i < 13; i++){
    ans += std::max(0,a[i]+b[i]-4);
  }

  std::cout << ans << "\n";
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