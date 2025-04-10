#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<int> dep(n + 1);
  std::vector<std::vector<int>> par(n + 1, std::vector<int>(31)),
      last(n + 1, std::vector<int>(31));
  auto dfs = [&](auto &&self, int u, int fa) -> void {
    dep[u] = dep[fa] + 1;
    par[u][0] = fa;
    for (int i = 1; i <= 30; ++i) {
      par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int i = 0; i <= 30; ++i) {
      if (a[u] >> i & 1) {
        last[u][i] = u;
      } else {
        last[u][i] = last[fa][i];
      }
    }
    for (const auto &v : adj[u]) {
      if (v != fa) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) {
      std::swap(u, v);
    }
    for (int i = 30; i >= 0; --i) {
      if (dep[par[u][i]] >= dep[v]) {
        u = par[u][i];
      }
    }
    for (int i = 30; i >= 0; --i) {
      if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
      }
    }
    return u == v ? u : par[v][0];
  };

  auto get_or = [&](int u, int u_lca) {
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
      if (dep[last[u][i]] >= dep[u_lca]) {
        ans += 1 << i;
      }
    }
    return ans;
  };

  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;

    int uv_lca = lca(u, v);

    int u_or = get_or(u, uv_lca);
    int v_or = get_or(v, uv_lca);

    int ans = 0;

    for (int i = 0; i <= 30; ++i) {
      if (dep[last[u][i]] >= dep[uv_lca]) {
        ans = std::max(
            ans, __builtin_popcount(get_or(u, last[u][i])) +
                     __builtin_popcount(get_or(last[u][i], uv_lca) | v_or));
      }
      if (dep[last[v][i]] >= dep[uv_lca]) {
        ans = std::max(
            ans, __builtin_popcount(get_or(v, last[v][i])) +
                     __builtin_popcount(get_or(last[v][i], uv_lca) | u_or));
      }
    }

    std::cout << ans << " \n"[q == 0];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}