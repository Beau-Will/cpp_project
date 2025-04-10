#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  s = " " + s;

  std::vector<int> pre(n + 1), suf(n + 2);
  std::set<char> set;
  for (int i = 1; i <= n; ++i) {
    set.insert(s[i]);
    pre[i] = set.size();
  }
  set.clear();
  for (int i = n; i >= 1; --i) {
    set.insert(s[i]);
    suf[i] = set.size();
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans = std::max(ans, pre[i] + suf[i + 1]);
  }

  std::cout << ans << "\n";
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