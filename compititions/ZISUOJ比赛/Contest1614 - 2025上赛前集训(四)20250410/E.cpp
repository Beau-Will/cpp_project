#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<std::vector<std::string>> map(6);
  std::vector<std::vector<std::vector<int>>> pre(6);
  for (int i = 0; i < n; ++i) {
    map[a[i].size()].push_back(a[i]);
  }
  for (int i = 1; i <= 5; ++i) {
    for (int j = 0; j < map[i].size(); ++j) {
      auto t = map[i][j];
      std::vector<int> s(t.size() + 1);
      for (int k = 0; k < t.size(); ++k) {
        s[k + 1] = s[k] + t[k] - '0';
      }
      pre[i].push_back(s);
    }
  }

  i64 ans = 0;
  for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
      if ((i + j) & 1) {
        continue;
      }
      int half = (i + j) / 2;
      if (i <= j) {
        std::vector<int> b(map[j].size());
        for (int k = 0; k < map[j].size(); ++k) {
          auto t = map[j][k];
          b[k] = (pre[j][k][t.size()] - pre[j][k][t.size() - half]) -
                 pre[j][k][t.size() - half];
        }
        std::sort(b.begin(), b.end());
        for (int k = 0; k < map[i].size(); ++k) {
          int tmp_pre = pre[i][k][map[i][k].size()];
          ans += std::upper_bound(b.begin(), b.end(), tmp_pre) -
                 std::lower_bound(b.begin(), b.end(), tmp_pre);
        }
      } else {
        std::vector<int> b(map[i].size());
        for (int k = 0; k < map[i].size(); ++k) {
          auto t = map[i][k];
          b[k] = pre[i][k][half] - (pre[i][k][t.size()] - pre[i][k][half]);
        }
        std::sort(b.begin(), b.end());
        for (int k = 0; k < map[j].size(); ++k) {
          int tmp_suf = pre[j][k][map[j][k].size()];
          ans += std::upper_bound(b.begin(), b.end(), tmp_suf) -
                 std::lower_bound(b.begin(), b.end(), tmp_suf);
        }
      }
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