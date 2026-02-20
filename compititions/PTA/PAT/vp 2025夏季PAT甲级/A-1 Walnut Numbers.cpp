#include <bits/stdc++.h>

void solve() {
  int x;
  std::cin >> x;

  auto check = [&]() {
    int t = x;
    std::vector<int> bit;
    while (t) {
      bit.push_back(t & 1);
      t >>= 1;
    }
    int t0 = 0, t1 = 0;
    for (int i = 0; i < bit.size(); i++) {
      if (bit[i]) {
        if (t0) {
          if (t0 == 3) {
            return true;
          }
          t0 = 0;
        }
        t1++;
      } else {
        if (t1) {
          if (t1 == 3) {
            return true;
          }
          t1 = 0;
        }
        t0++;
      }
    }
    if (t0) {
      if (t0 == 3) {
        return true;
      }
    }
    if (t1) {
      if (t1 == 3) {
        return true;
      }
    }
    return false;
  };

  std::cout << (check() ? "yes\n" : "no\n");
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for (int Ti = 0; Ti < T; Ti++) {
    solve();
  }

  return 0;
}