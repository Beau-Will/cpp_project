#include <bits/stdc++.h>

constexpr int inf = 2E9;

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::array<int, 2>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int t;
  std::cin >> t;

  std::vector<bool> is(n + 1);
  for (int i = 0; i < t; i++) {
    int x;
    std::cin >> x;
    is[x] = true;
  }

  int st, ed;
  std::cin >> st >> ed;

  auto dijkstra1 = [&]() {
    std::vector<int> dist(n + 1, inf);
    std::vector<int> cnt(n + 1);
    std::vector<bool> vis(n + 1);

    using Node = std::array<int, 2>;
    std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;
    heap.push({0, st});
    dist[st] = 0;
    if (is[st]) {
      return std::array{inf, -1};
    }
    cnt[st] = 1;

    while (heap.size()) {
      auto [distance, u] = heap.top();
      heap.pop();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (const auto& [v, w] : adj[u]) {
        if (is[v]) {
          continue;
        }
        if (distance + w < dist[v]) {
          dist[v] = distance + w;
          cnt[v] = cnt[u] + 1;
          heap.push({dist[v], v});
        } else if (distance + w == dist[v]) {
          cnt[v] = std::max(cnt[v], cnt[u] + 1);
        }
      }
    }

    return std::array{dist[ed], cnt[ed]};
  };

  auto [dist1, cnt1] = dijkstra1();

  if (dist1 != inf) {
    std::cout << dist1 << " " << cnt1 << "\n";
    return;
  }

  auto dijkstra2 = [&]() {
    std::vector<int> dist(n + 1, inf);
    std::vector<int> cnt(n + 1);
    std::vector<bool> vis(n + 1);

    using Node = std::array<int, 2>;
    std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;
    heap.push({0, st});
    dist[st] = 0;
    cnt[st] = (is[st] ? 1 : 0);

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
          if (is[v]) cnt[v] = cnt[u] + 1;
          else cnt[v] = cnt[u];
          heap.push({dist[v], v});
        } else if (distance + w == dist[v]) {
          if (is[v]) cnt[v] = std::min(cnt[v], cnt[u] + 1);
          else cnt[v] = std::min(cnt[v], cnt[u]);
        }
      }
    }

    return std::array{dist[ed], cnt[ed]};
  };

  auto [dist2, cnt2] = dijkstra2();

  std::cout << dist2 << " " << cnt2 << "\n";
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