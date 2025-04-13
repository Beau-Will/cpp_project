#include <bits/stdc++.h>

using i64 = long long;

bool check(int x) {
  if (x < 8) {
    if (x == 6 || x == 4) {
      return true;
    }
    return false;
  }
  for (int i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      if (i ^ (x / i)) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (check(a[i] * 2)) {
      ++ans;
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}