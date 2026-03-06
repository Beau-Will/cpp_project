#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector map(10, std::vector(3, std::string(2, '?')));
  map[0] = {".*", "**", ".."};
  map[1] = {"*.", "..", ".."};
  map[2] = {"*.", "*.", ".."};
  map[3] = {"**", "..", ".."};
  map[4] = {"**", ".*", ".."};
  map[5] = {"*.", ".*", ".."};
  map[6] = {"**", "*.", ".."};
  map[7] = {"**", "**", ".."};
  map[8] = {"*.", "**", ".."};
  map[9] = {".*", "*.", ".."};

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> g(n);
  for (int i = 0; i < n; i++) {
    std::cin >> g[i];
  }

  auto check = [&](int i, int j) {
    std::vector t(3, std::string(2, '?'));
    t[0] = g[i].substr(j, 2);
    t[1] = g[i + 1].substr(j, 2);
    t[2] = g[i + 2].substr(j, 2);

    for (int i = 0; i < 10; i++) {
      if (t == map[i]) {
        return i;
      }
    }
    return 10;
  };

  std::vector<int> cnt(11);
  for (int i = 0; i + 2 < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      cnt[check(i, j)]++;
    }
  }

  for (int i = 1; i < 10; i++) {
    std::cout << cnt[i] << " ";
  }
  std::cout << cnt[0] << "\n";

  return 0;
}