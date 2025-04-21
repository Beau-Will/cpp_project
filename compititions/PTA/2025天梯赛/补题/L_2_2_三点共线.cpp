#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n;
  std::cin >> n;

  using Point = std::pair<int, int>;

  auto b = std::vector(3, std::vector<int>());
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    b[y].push_back(x);
  }

  for (int i = 0; i < 3; ++i) {
    std::sort(all(b[i]));
    b[i].erase(std::unique(all(b[i])), b[i].end());
  }

  int min = *min_element(all(b[2]));
  int max = *max_element(all(b[2]));

  std::vector<bool> has_y2(max - min + 1);
  for (auto x : b[2]) {
    has_y2[x - min] = true;
  }

  using Ans = std::array<Point, 3>;

  std::vector<Ans> ans;

  for (auto x1 : b[1]) {
    for (auto x0 : b[0]) {
      int diff1 = x1 - x0;
      int x2 = x1 + diff1;
      if (x2 < min || x2 - min >= has_y2.size()) {
        continue;
      }
      if (has_y2[x2 - min]) {
        Ans t;
        t[1] = {x1, 1};
        t[0] = {x0, 0};
        t[2] = {x2, 2};
        ans.push_back(t);
      }
    }
  }

  if (ans.size() == 0) {
    std::cout << "-1\n";
    return;
  }

  for (auto &t : ans) {
    for (int i = 0; i < 3; ++i) {
      auto [x, y] = t[i];
      if (i == 0) {
        std::cout << "[" << x << ", " << y << "]";
      } else {
        std::cout << " [" << x << ", " << y << "]";
      }
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}