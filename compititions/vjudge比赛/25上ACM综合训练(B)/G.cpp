#include <bits/stdc++.h>

using i64 = long long;

struct Node {
  int a;
  char b;
  int c;
  char d;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::string t = "wwiinn";
  t = " " + t;

  std::vector<std::vector<int>> adj(7);
  for (int i = 1; i <= n; ++i) {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] == 'w') {
        ++cnt1;
      } else if (a[i][j] == 'i') {
        ++cnt2;
      } else {
        ++cnt3;
      }
    }
    if (cnt1 > 1 && cnt2 == 0) {
      adj[1].push_back(i);
    }
    if (cnt1 > 1 && cnt3 == 0) {
      adj[2].push_back(i);
    }
    if (cnt2 > 1 && cnt3 == 0) {
      adj[3].push_back(i);
    }
    if (cnt2 > 1 && cnt1 == 0) {
      adj[4].push_back(i);
    }
    if (cnt3 > 1 && cnt1 == 0) {
      adj[5].push_back(i);
    }
    if (cnt3 > 1 && cnt2 == 0) {
      adj[6].push_back(i);
    }
  }

  std::vector<Node> ans;
  for (int i = 1; i <= 3; ++i) {
    while (adj[i].size() && adj[i + 3].size()) {
      ans.push_back({adj[i].back(), t[i], adj[i + 3].back(), t[i + 3]});
      adj[i].pop_back();
      adj[i + 3].pop_back();
    }
  }
  for (int i = 1; i <= 2; ++i) {
    while (adj[i].size()) {
      ans.push_back({adj[i].back(), t[i], adj[i + 2].back(), t[i + 2]});
      if (i == 1) {
        ans.push_back({adj[3].back(), t[1], adj[5].back(), t[5]});
      } else {
        ans.push_back({adj[2].back(), t[4], adj[6].back(), t[6]});
      }
      //   ans.push_back({adj[i + 2 - (i == 2) * 2].back(), t[i + (i == 2) * 2],
      //                  adj[i + 4].back(), t[i + 4]});
      //                  //i==1 -> (1,3) (3,5)
      //                  //i==2 -> (2,4) (2,6)
      adj[i].pop_back();
      adj[i + 2].pop_back();
      adj[i + 4].pop_back();
    }
  }
  std::cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i) {
    std::cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << " "
              << ans[i].d << "\n";
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