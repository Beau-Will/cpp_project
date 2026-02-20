#include <bits/stdc++.h>

struct DSU {
  std::vector<int> f, siz;

  DSU(int n) {
    f.resize(n + 1);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n + 1, 1);
  }

  int find(int x) {
    if (x != f[x]) {
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv) {
      return false;
    }
    if (fv > fu) {
      std::swap(fu, fv);
    }
    f[fv] = fu;
    siz[fu] += siz[fv];
    return true;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> adj(n + 1);
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
    dsu.merge(u, v);
  }

  std::map<int, std::vector<int>> map;
  for (int i = 1; i <= n; i++) {
    map[dsu.find(i)].push_back(i);
  }

  int ans1 = 0, ans2 = -1;
  for (const auto& [u, v] : map) {
    int cnt1 = 0;
    int sum = 0;
    for (const auto& i : v) {
      if (adj[i].size() == 1) {
        cnt1++;
      }
      sum += adj[i].size();
    }
    if (cnt1 == 2 && sum == (dsu.siz[u] - 1) * 2 || dsu.siz[u] == 1) {
      ans1++;
      if (sum / 2 > ans2) {
        ans2 = sum / 2;
      }
    }
  }

  std::cout << ans1 << " " << ans2 << "\n";
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