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
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(6);
  for (int i = 1; i <= 5; ++i) {
    std::cin >> a[i];
  }
  a[0] = 1;

  std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  auto dist = std::vector(6, std::vector<int>(n + 1, inf1));
  auto vis = std::vector(6, std::vector<bool>(n + 1));

  auto dijkstra = [&]() {
    using pii = std::pair<int, int>;
    for (int i = 0; i < 6; ++i) {
      int s = a[i];

      std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

      dist[i][s] = 0;
      pq.push({dist[i][s], s});

      while (!pq.empty()) {
        auto [w1, u] = pq.top();
        pq.pop();

        if (vis[i][u]) {
          continue;
        }
        vis[i][u] = true;

        for (auto &[v, w2] : adj[u]) {
          if (dist[i][u] + w2 < dist[i][v]) {
            dist[i][v] = dist[i][u] + w2;
            pq.push({dist[i][v], v});
          }
        }
      }
    }
  };

  dijkstra();

  int ans = inf1;
  std::vector<int> st(6);

  auto dfs = [&](auto &&self, int u, int s, int sum) -> void {
    if (u > 5) {
      ans = std::min(ans, sum);
      return;
    }

    for (int i = 1; i <= 5; ++i) {
      if (st[i]) {
        continue;
      }

      st[i] = true;
      self(self, u + 1, i, sum + dist[s][a[i]]);
      st[i] = false;
    }
  };

  dfs(dfs, 1, 0, 0);

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