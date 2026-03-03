#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }

  std::vector<bool> vis(n + 1);
  for (int u = 1; u <= n; u++) {
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    if (!s.count(u)) {
      continue;
    }
    for (const auto& v : adj[u]) {
      if (vis[v]) {
        continue;
      }
      if (s.count(v)) {
        s.erase(v);
      }
    }
  }

  bool isFirst = true;
  for (const auto& ele : s) {
    if (isFirst) {
      isFirst = false;
    } else {
      std::cout << " ";
    }
    std::cout << ele;
  }

  std::cout << "\n";

  return 0;
}