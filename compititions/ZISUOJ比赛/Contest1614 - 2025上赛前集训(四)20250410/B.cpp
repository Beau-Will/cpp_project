#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  std::vector<int> cnt(26);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  int cnt1 = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] & 1) {
      ++cnt1;
    }
  }

  if ((n - k) & 1) {
    if (k >= cnt1 - 1) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  } else {
    if (k >= cnt1) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}