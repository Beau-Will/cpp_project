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

  int K;
  std::cin >> K;

  for (int ki = 0; ki < K; ki++) {
    int k;
    std::cin >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
      std::cin >> a[i];
    }

    std::vector<bool> vis(n + 1);
    std::queue<int> q;

    for (int i = 0; i < k; i++) {
      q.push(a[i]);
      vis[a[i]] = true;
    }

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (const auto& v : adj[u]) {
        if (vis[v]) {
          continue;
        }
        vis[v] = true;
      }
    }

    bool isok = true;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        isok = false;
        break;
      }
    }

    std::cout << (isok ? "yes\n" : "no\n");
  }

  return 0;
}