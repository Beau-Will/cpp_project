#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve() {
  int n = 2;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  //   std::cout << a[0] << "\n" << a[1] << "\n";

  int m = a[0].size();
  std::vector<std::pair<int, int>> b;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j][i] == '#') {
        b.push_back({j, i});
      }
    }
  }

  //   for (int i = 0; i < b.size(); ++i) {
  //     std::cout << b[i].first << " " << b[i].second << "\n";
  //   }

  std::vector<int> fa(b.size());
  std::iota(fa.begin(), fa.end(), 0);

  std::function<int(int)> find = [&](int u) {
    if (fa[u] != u) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  };

  auto merge = [&](int u, int v) {
    int u_fa = find(u);
    int v_fa = find(v);
    if (u_fa == v_fa) {
      return false;
    }
    fa[v_fa] = u_fa;
    return true;
  };

  for (int i = 0; i < b.size() - 1; ++i) {
    int x1 = b[i].first, y1 = b[i].second;
    int x2 = b[i + 1].first, y2 = b[i + 1].second;
    if ((y1 == y2) || (y2 == y1 + 1 && x1 == x2)) {
      merge(i, i + 1);
      //   std::cout << "merge i,i+1:" << i << "," << i + 1 << "\n";
    }
    if (i < b.size() - 2) {
      int x3 = b[i + 2].first, y3 = b[i + 2].second;
      if ((y1 == y3) || (y1 + 1 == y3 && x1 == x3)) {
        merge(i, i + 2);
        // std::cout << "merge i,i+2:" << i << "," << i + 2 << "\n";
      }
    }
  }

  std::vector<std::vector<std::pair<int, int>>> map(b.size());
  for (int i = 0; i < b.size(); ++i) {
    map[find(i)].push_back(b[i]);
  }

  //   for (int i = 0; i < b.size(); ++i) {
  //     std::cout << map[i].size() << "\n";
  //     if (map[i].size() != 0) {
  //       for (int j = 0; j < map[i].size(); ++j) {
  //         int x = map[i][j].first, y = map[i][j].second;
  //         std::cout << x << " " << y << "\n";
  //       }
  //     }
  //   }

  auto dist = [&](std::pair<int, int> &t1, std::pair<int, int> &t2) {
    return std::abs(t2.first - t1.first) + std::abs(t2.second - t1.second);
  };

  //   std::cout << "-----\n";

  int ans = 0;

  std::pair<int, int> tmp = {-1, -1};
  std::pair<int, int> last1 = {-1, -1};
  std::pair<int, int> last2 = {-1, -1};
  for (int i = 0; i < b.size(); ++i) {
    if (map[i].size() == 0) {
      continue;
    }

    if (last1 == tmp && last2 == tmp) {
      last1 = map[i].back();
      last2 = map[i].back();
      if (map[i].size() > 1) {
        last2 = map[i][map[i].size() - 2];
      }
      continue;
    }

    std::pair<int, int> cur_front1 = map[i].front();
    auto cur_front2 = cur_front1;
    std::pair<int, int> cur_last1 = map[i].back();
    auto cur_last2 = cur_last1;
    if (map[i].size() > 1) {
      cur_front2 = map[i][1];
      cur_last2 = map[i][map[i].size() - 2];
    }

    // std::cout << "*****\n";

    // std::cout << cur_front1.first << " " << cur_front1.second << "\n";
    // std::cout << cur_front2.first << " " << cur_front2.second << "\n";
    // std::cout << cur_last1.first << " " << cur_last1.second << "\n";
    // std::cout << cur_last2.first << " " << cur_last2.second << "\n";

    // std::cout << "*****\n";

    // std::cout << last1.first << " " << last1.second << "\n";
    // std::cout << last2.first << " " << last2.second << "\n";

    // std::cout << "*****\n";

    int min = inf;

    min = std::min(min, dist(last1, cur_front1));
    min = std::min(min, dist(last1, cur_front2));
    min = std::min(min, dist(last2, cur_front1));
    min = std::min(min, dist(last2, cur_front2));
    // std::cout << min << "\n";

    last1 = cur_last1;
    last2 = cur_last2;

    ans += min - 1;
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