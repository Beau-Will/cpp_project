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
  int n, m1, m2, s;
  std::cin >> n >> m1 >> m2 >> s;

  std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m1; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  std::vector<std::vector<int>> map(n + 1);
  std::vector<int> fa(n + 1);
  int cnt = 0;

  auto dfs = [&](auto &&self, int u, int id) -> void {
    fa[u] = id;
    map[id].push_back(u);

    for (auto &[v, w] : adj[u]) {
      if (!fa[v]) {
        self(self, v, id);
      }
    }
  };

  for (int i = 1; i <= n; ++i) {
    if (!fa[i]) {
      dfs(dfs, i, ++cnt);
    }
  }

  std::vector<int> in(n + 1);

  for (int i = 0; i < m2; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    ++in[fa[v]];
  }

  std::queue<int> q;
  std::vector<int> dist(n + 1, inf1);
  std::vector<bool> vis(n + 1);

  auto dijkstra = [&](int id) {
    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;

    for (auto &x : map[id]) {
      heap.push({dist[x], x});
    }

    while (!heap.empty()) {
      auto [w1, u] = heap.top();
      heap.pop();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (auto &[v, w2] : adj[u]) {
        if (fa[u] == fa[v]) {
          if (dist[u] + w2 < dist[v]) {
            dist[v] = dist[u] + w2;
            heap.push({dist[v], v});
          }
        } else {
          if (--in[fa[v]] == 0) {
            q.push(fa[v]);
          }
          if (dist[u] + w2 < dist[v]) {
            dist[v] = dist[u] + w2;
          }
        }
      }
    }
  };

  auto toposort = [&]() {
    dist[s] = 0;

    for (int i = 1; i <= cnt; ++i) {
      if (in[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      dijkstra(t);
    }
  };

  toposort();

  for (int i = 1; i <= n; ++i) {
    if (dist[i] > inf3 / 2) {
      std::cout << "NO PATH\n";
    } else {
      std::cout << dist[i] << "\n";
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