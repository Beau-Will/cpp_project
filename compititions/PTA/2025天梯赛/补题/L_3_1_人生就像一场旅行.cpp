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
  int b, n, m, k;
  std::cin >> b >> n >> m >> k;

  using Node = std::tuple<int, int, int>;

  std::vector<std::vector<Node>> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v, w1, w2;
    std::cin >> u >> v >> w1 >> w2;
    adj[u].push_back({v, w1, w2});
    adj[v].push_back({u, w1, w2});
  }

  auto dijkstra = [&](int st) {
    std::vector<int> dist(n + 1, inf1), val(n + 1);
    std::vector<bool> vis(n + 1);

    using pii = std::pair<int, int>;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
      auto [w, u] = pq.top();
      pq.pop();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (auto [v, w1, w2] : adj[u]) {
        if (dist[u] + w1 < dist[v]) {
          dist[v] = dist[u] + w1;
          val[v] = val[u] + w2;
          pq.push({dist[v], v});
        } else if (dist[u] + w1 == dist[v]) {
          val[v] = std::max(val[v], val[u] + w2);
        }
      }
    }

    std::vector<pii> res(n + 1);
    for (int i = 1; i <= n; ++i) {
      res[i].fi = dist[i];
      res[i].se = val[i];
    }

    return res;
  };

  for (; k--;) {
    int s;
    std::cin >> s;

    auto res = dijkstra(s);

    std::vector<int> ans1, ans2;
    int max = -1;

    for (int i = 1; i <= n; ++i) {
      if (s == i) {
        continue;
      }
      if (res[i].fi <= b) {
        ans1.push_back(i);
        max = std::max(max, res[i].se);
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (s == i) {
        continue;
      }
      if (res[i].fi <= b) {
        if (res[i].se == max) {
          ans2.push_back(i);
        }
      }
    }

    if (ans1.size() == 0) {
      std::cout << "T_T\n";
      continue;
    }

    for (int i = 0; i < ans1.size(); ++i) {
      std::cout << ans1[i] << " \n"[i + 1 == ans1.size()];
    }

    for (int i = 0; i < ans2.size(); ++i) {
      std::cout << ans2[i] << " \n"[i + 1 == ans2.size()];
    }
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