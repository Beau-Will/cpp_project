#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n, m, x, y;
  std::cin >> n >> m >> x >> y;

  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i];
  }

  int t1 = 0, t2 = 0; // t1是理论最多可以燃放鞭炮的数量，t2是兔兔可以逃跑的时间
  if (x < y) {
    t1 = y - x - 1;
    t2 += x - 1;
  } else {
    t1 = x - y - 1;
    t2 += n - x;
  }

  if (t1 == 0) {
    std::cout << "0\n";
    return;
  }

  std::sort(a.begin(), a.end());
  int idx = std::upper_bound(a.begin(), a.end(), t1 + t2) - a.begin();
  if (idx == 0) {
    std::cout << "0\n";
    return;
  }
  --idx;

  int ans = 0;
  int base = t1 + t2;
  for (int i = idx; i >= 0; --i) {
    if (a[i] <= base) {
      ++ans;
      --base;
    }
    if (ans == t1) {
      break;
    }
  }

  std::cout << ans << "\n";
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