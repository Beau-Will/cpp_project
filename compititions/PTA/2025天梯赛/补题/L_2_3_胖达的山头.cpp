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

  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int h1 = std::stoi(str1.substr(0, 2));
    int m1 = std::stoi(str1.substr(3, 2));
    int s1 = std::stoi(str1.substr(6, 2));
    int h2 = std::stoi(str2.substr(0, 2));
    int m2 = std::stoi(str2.substr(3, 2));
    int s2 = std::stoi(str2.substr(6, 2));
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    a[i] = {t1, t2};
  }

  std::vector<int> b(24 * 3600 + 1);
  for (auto &[l, r] : a) {
    ++b[l];
    --b[r + 1];
  }

  int sum = 0, ans = 0;
  for (int i = 0; i <= 24 * 3600; ++i) {
    sum += b[i];
    ans = std::max(ans, sum);
  }

  std::cout << ans << "\n";
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