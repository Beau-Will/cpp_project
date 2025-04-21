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
  std::string s1, s2;
  std::cin >> n >> s1 >> s2;

  i64 l = std::stoll(s1), r = std::stoll(s2);

  std::set<i64> set;

  auto dfs = [&](auto &&self, int len, i64 x) -> void {
    if (len == n) {
      if (x >= l && x <= r) {
        set.insert(x);
      }
      return;
    }
    for (int i = 0; i < 10; ++i) {
      if ((x * 10 + i) % (len + 1) != 0) {
        continue;
      }
      self(self, len + 1, x * 10 + i);
    }
  };

  for (int i = s1.front() - '0'; i <= s2.front() - '0'; ++i) {
    dfs(dfs, 1, 1LL * i);
  }

  if (set.size() == 0) {
    std::cout << "No Solution\n";
    return;
  }

  for (auto &ele : set) {
    std::cout << ele << "\n";
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