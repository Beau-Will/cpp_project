#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  auto check = [&](int x) {
    std::vector<int> dist(n + 1, inf1);
    std::vector<bool> vis(n + 1);

    std::deque<int> q;
    q.push_back(1);
    dist[1] = 0;

    while (!q.empty()) {
      auto u = q.front();
      q.pop_front();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (auto &[v, w] : adj[u]) {
        int t = w > x;
        if (dist[u] + t < dist[v]) {
          dist[v] = dist[u] + t;
          if (t) {
            q.push_back(v);
          } else {
            q.push_front(v);
          }
        }
      }
    }

    return dist[n] <= k;
  };

  int l = 0, r = 1000001;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  std::cout << (l != 1000001 ? l : -1) << "\n";
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