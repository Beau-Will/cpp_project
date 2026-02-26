#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;

  std::unordered_map<std::string, std::vector<int>> map;
  std::unordered_map<int, std::string> at;
  std::vector<int> all;
  all.reserve(n);
  std::unordered_map<int, bool> won;
  for (int i = 0; i < n; i++) {
    std::string id;
    int x;
    std::cin >> id >> x;

    map[id].push_back(x);
    at[x] = id;
    all.push_back(x);
  }

  std::sort(all.begin(), all.end());

  int q;
  std::cin >> q;

  for (int qi = 0; qi < q; qi++) {
    int op;
    std::cin >> op;

    if (op == 1) {
      int x;
      std::cin >> x;
      auto it = std::lower_bound(all.begin(), all.end(), x);
      if (it == all.end()) {
        std::cout << "ERROR\n";
      } else {
        std::cout << at[*it] << "\n";
        won[*it] = true;
      }
    } else if (op == 2) {
      std::string id;
      std::cin >> id;

      auto it = map.find(id);
      if (it == map.end()) {
        std::cout << "ERROR\n";
      } else {
        const auto& t = it->second;
        std::vector<int> ans;
        for (const auto& _ : t) {
          if (won[_]) {
            ans.push_back(_);
          }
        }
        if (ans.empty()) {
          std::cout << "\n";
        } else {
          for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << " \n"[i + 1 == ans.size()];
          }
        }
      }
    } else {
      int x;
      std::cin >> x;

      auto it = std::lower_bound(all.begin(), all.end(), x);
      if (it == all.end()) {
        std::cout << "ERROR\n";
      } else if (*it != x) {
        std::cout << "ERROR\n";
      } else {
        std::cout << at[*it] << "\n";
        won[*it] = true;
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for (int Ti = 0; Ti < T; Ti++) {
    solve();
  }

  return 0;
}