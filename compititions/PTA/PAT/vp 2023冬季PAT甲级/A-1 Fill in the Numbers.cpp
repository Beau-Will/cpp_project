#include <bits/stdc++.h>

constexpr std::array dx = {0, 0, -1, 1};
constexpr std::array dy = {-1, 1, 0, 0};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector g(n, std::vector<int>(n));
  std::map<int, std::array<int, 2>> at;

  std::vector<int> res(m + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        std::cin >> g[j][k];
      }
    }

    bool isok = true;
    at.clear();
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (at.count(g[j][k])) {
          isok = false;
          goto t;
        }
        at[g[j][k]] = {j, k};
      }
    }
t:
    ;
    if (!isok) {
      continue;
    }

    for (int j = 1; j <= n * n; j++) {
      auto [x, y] = at[j];
      auto [u, v] = at[(j % (n * n)) + 1];

      if (std::abs(u - x) + std::abs(v - y) != 1) {
        isok = false;
        break;
      }
    }

    if (!isok) {
      continue;
    }
    int sum = 0;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (j == k) {
          sum += g[j][k];
        } else if (j + k == n - 1) {
          sum += g[j][k];
        }
      }
    }

    res[i] = sum;
  }

  int max = *std::max_element(res.begin() + 1, res.end());

  if (max == 0) {
    std::cout << "0\n";
    return 0;
  }

  std::vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (res[i] == max) {
      ans.push_back(i);
    }
  }

  std::cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }

  return 0;
}