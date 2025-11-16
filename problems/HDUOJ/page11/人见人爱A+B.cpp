#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int ah,am,as,bh,bm,bs;
  std::cin >> ah >> am >> as >> bh >> bm >> bs;

  int t1 = (as+bs)/60;
  as = (as+bs)%60;
  int t2 = (am+bm+t1)/60;
  am = (am+bm+t1)%60;
  ah += bh+t2;

  std::cout << ah << " " << am << " " << as << "\n";
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