#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> adj(n + 1);
  int rt = -1;
  for (int i = 1; i <= n; i++) {
    int par;
    std::cin >> par;
    if (par == -1) {
      rt = i;
    } else {
      adj[par].push_back(i);
      adj[i].push_back(par);
    }
  }

  std::vector<int> dep(n + 1);
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    for (const auto& v : adj[u]) {
      if (v == fa) {
        continue;
      }
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  };

  dfs(rt, -1);
  int max = *std::max_element(dep.begin() + 1, dep.end());
  int t = -1;
  for (int i = 1; i <= n; i++) {
    if (dep[i] == max) {
      t = i;
      break;
    }
  }

  dep[t] = 0;
  dfs(t, -1);

  max = *std::max_element(dep.begin() + 1, dep.end());
  std::cout << max << "\n";
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