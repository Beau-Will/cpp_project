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
  std::string s;
  std::cin >> s;

  std::vector<int> a(26);
  for (int i = 0; i < 26; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> cnt(26);
  int ans = 0;
  for (auto &c : s) {
    ++cnt[c - 'a'];
    ans += a[c - 'a'];
  }

  for (int i = 0; i < 26; ++i) {
    std::cout << cnt[i] << " \n"[i + 1 == 26];
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