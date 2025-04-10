#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  i64 n;
  std::cin >> n;

  std::vector<int> a(60);
  for (int i = 0; i < 60; ++i) {
    if (1LL << i & n) {
      a[i] = 1;
    }
  }

  std::vector<std::string> b(10);
  for (int i = 9; i >= 0; --i) {
    std::string t;
    for (int j = (i + 1) * 6 - 1; j >= i * 6; --j) {
      t += '0' + a[j];
    }
    b[i] = t;
  }

  bool flag = false;
  std::vector<std::string> c;
  for (int i = 9; i >= 0; --i) {
    if (std::count(b[i].begin(), b[i].end(), '1') || flag) {
      flag = true;
      std::string t = b[i].substr(0, 3);
      t = "1" + t;
      c.push_back(t);
      t = b[i].substr(3, 3);
      t = "1" + t;
      c.push_back(t);
    }
  }

  std::string ans;
  for (int i = 0; i < c.size(); ++i) {
    int t = 0;
    for (int j = 3; j >= 0; --j) {
      if (c[i][j] == '1') {
        t |= 1 << (3 - j);
      }
    }
    if (t < 10) {
      ans += '0' + t;
    } else {
      ans += 'A' + t - 10;
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  //   std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}