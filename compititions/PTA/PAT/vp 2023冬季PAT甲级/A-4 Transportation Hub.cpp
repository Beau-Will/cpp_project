#include <bits/stdc++.h>

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<std::array<int, 2>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  std::vector<int> dists(n), distt(n);
  std::vector<int> cnts(n), cntt(n);
  auto dijkstra = [&](std::vector<int>& dist, std::vector<int>& cnt, int s) {
    std::vector<bool> vis(n);
    using Node = std::array<int, 2>;
    std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;
    heap.push({0, s});
    dist[s] = 0;
    cnt[s] = 1;

    while (heap.size()) {
      auto [distance, u] = heap.top();
      heap.pop();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (const auto& [v, w] : adj[u]) {
        if (distance + w < dist[v]) {
          dist[v] = distance + w;
          cnt[v] = cnt[u];
          heap.push({dist[v], v});
        } else if (distance + w == dist[v]) {
          cnt[v] += cnt[u];
        }
      }
    }
  };

  int q;
  std::cin >> q;

  for (int qi = 0; qi < q; qi++) {
    int s, t;
    std::cin >> s >> t;

    dists.assign(n, inf);
    distt.assign(n, inf);
    cnts.assign(n, 0);
    cntt.assign(n, 0);
    dijkstra(dists, cnts, s);
    dijkstra(distt, cntt, t);

    if (dists[t] == inf) {
      std::cout << "None\n";
      continue;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i == s || i == t) {
        continue;
      }
      if (dists[i] + distt[i] == dists[t]) {
        if (1LL * cnts[i] * cntt[i] >= k) {
          ans.push_back(i);
        }
      }
    }

    if (ans.size() == 0) {
      std::cout << "None\n";
      continue;
    }

    for (int i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
  }

  return 0;
}