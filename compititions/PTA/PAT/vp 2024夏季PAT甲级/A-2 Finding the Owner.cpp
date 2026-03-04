#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;
  std::cin >> s;

  int n;
  std::cin >> n;

  std::vector<std::string> t(n);
  for (int i = 0; i < n; i++) {
    std::cin >> t[i];
  }

  auto check = [&](const std::string & x) {
    if (s[7] != x[7] || s[8] != x[8]) {
      return false;
    }
    if (s[9] != x[4]) {
      return false;
    }
    if (s[10] != x[17]) {
      return false;
    }
    return true;
  };

  std::string ans;
  for (int i = 0; i < n; i++) {
    if (check(t[i])) {
      ans = t[i];
    }
  }

  std::cout << ans << "\n";

  return 0;
}