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
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> pre(n + 1);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + (a[i] <= k ? -1 : 1);
  }

  if (*std::min_element(pre.begin() + 2, pre.begin() + n) < 0) {
    std::cout << "YES\n";
    return;
  }
  if (std::count(pre.begin() + 2, pre.begin() + n, 0) > 1) {
    std::cout << "YES\n";
    return;
  }
  if (*std::max_element(pre.begin() + 1, pre.begin() + n - 1) > pre[n]) {
    std::cout << "YES\n";
    return;
  }
  if (std::count(pre.begin() + 1, pre.begin() + n - 1, pre[n]) > 1) {
    std::cout << "YES\n";
    return;
  }

  int l = 1, r = n - 1;
  while (l < r && pre[l] > 0) {
    ++l;
  }
  while (r > l && pre[r] < pre[n]) {
    --r;
  }

  if (r > l) {
    std::cout << "YES\n";
    return;
  }

  std::cout << "NO\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}