#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  std::vector<std::array<int, 2>> edges;
  int u, v;
  while (std::cin >> u) {
    if (u == 0) {
      break;
    }
    std::cin >> v;

    adj[u].push_back(v);
    edges.push_back({u, v});
  }

  for (int i = 1; i <= n; i++) {
    std::sort(adj[i].begin(), adj[i].end());
    adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
  }
  std::sort(edges.begin(), edges.end());
  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

  std::vector<int> ind(n + 1);
  for (int u = 1; u <= n; u++) {
    for (const auto& v : adj[u]) {
      ind[v]++;
    }
  }

  int cnt = std::count(ind.begin() + 1, ind.end(), 0);

  if (edges.size() != n - 1 || cnt != 1) {
    std::cout << "no " << cnt << "\n";
  } else {
    int rt = 1;
    for (int i = 1; i <= n; i++) {
      if (ind[i] == 0) {
        rt = i;
        break;
      }
    }

    std::vector<int> vis(n + 1);
    std::queue<int> q;
    q.push(rt);
    vis[rt] = true;

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (const auto& v : adj[u]) {
        if (vis[v]) {
          continue;
        }
        vis[v] = true;
        q.push(v);
      }
    }

    bool isok = true;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        isok = false;
        break;
      }
    }
    
    if (!isok) {
      std::cout << "no " << cnt << "\n";
    } else {
      std::cout << "yes " << rt << "\n";
    }
  }

  return 0;
}