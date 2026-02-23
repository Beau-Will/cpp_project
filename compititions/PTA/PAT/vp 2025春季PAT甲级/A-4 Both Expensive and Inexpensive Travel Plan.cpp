#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::map<std::array<int, 2>, int> map;
  std::vector<std::vector<std::array<int, 2>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    if (v > u) {
      std::swap(u, v);
    }
    map[ {u, v}] = std::max(map[ {u, v}], w);
  }

  for (const auto& [t, w] : map) {
    auto [u, v] = t;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int st = -1, ed = -1;
  std::cin >> st >> ed;

  std::map<int, int> prev;
  std::vector<int> dist(n + 1, inf);
  auto dijkstra = [&]() {
    std::vector<bool> vis(n + 1);
    using Node = std::array<int, 2>;
    std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;
    heap.push({0, st});
    dist[st] = 0;

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
          heap.push({dist[v], v});
          prev[v] = u;
        } else if (distance + w == dist[v] && a[u]) {
          prev[v] = u;
        }
      }
    }
  };

  dijkstra();

  if (dist[ed] == inf) {
    std::cout << "Sorry\n";
    return;
  }

  std::cout << dist[ed] << "\n";

  std::vector<int> ans;
  ans.push_back(ed);

  while (ed != st) {
    ed = prev[ed];
    ans.push_back(ed);
  }

  std::reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << (i + 1 == ans.size() ? "\n" : "->");
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for (int Ti = 0; Ti < T; Ti++) {
    solve();
  }

  return 0;
}