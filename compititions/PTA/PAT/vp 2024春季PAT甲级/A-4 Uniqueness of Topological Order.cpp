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
  }

  std::vector<int> in(n + 1);
  for (int u = 1; u <= n; u++) {
    for (const auto& v : adj[u]) {
      in[v]++;
    }
  }

  int min = *std::min_element(in.begin() + 1, in.end());
  std::vector<int> ans1;
  for (int i = 1; i <= n; i++) {
    if (in[i] == min) {
      ans1.push_back(i);
    }
  }
  for (int i = 0; i < ans1.size(); i++) {
    std::cout << ans1[i] << " \n"[i + 1 == ans1.size()];
  }

  std::vector<int> tmp = in;

  std::vector<int> ans2, ans3;
  auto topo_sort1 = [&]() {
    std::queue<int> q;

    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) {
        q.push(i);
        ans2.push_back(i);
      }
    }

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (const auto& v : adj[u]) {
        if (--in[v] == 0) {
          q.push(v);
          ans2.push_back(v);
        }
      }
    }

    return ans2.size() == n;
  };
  auto topo_sort2 = [&]() {
    in = tmp;
    std::queue<int> q;

    for (int i = n; i >= 1; i--) {
      if (in[i] == 0) {
        q.push(i);
        ans3.push_back(i);
      }
    }

    while (q.size()) {
      auto u = q.front();
      q.pop();

      for (int j = adj[u].size() - 1; j >= 0; j--) {
        int v = adj[u][j];
        if (--in[v] == 0) {
          q.push(v);
          ans3.push_back(v);
        }
      }
    }

    return ans3.size() == n;
  };

  bool isok1 = topo_sort1();
  bool isok2 = topo_sort2();

  if (!isok1 || !isok2 || ans1.size() > 1) {
    std::cout << "No\n";
    return 0;
  }

  bool isok = true;
  for (int i = 0; i < ans2.size(); i++) {
    if (ans2[i] != ans3[i]) {
      isok = false;
      break;
    }
  }

  if (!isok) {
    std::cout << "No\n";
    return 0;
  }

  std::cout << "Yes\n";
  for (int i = 0; i < ans2.size(); i++) {
    std::cout << ans2[i] << " \n"[i + 1 == ans2.size()];
  }

  return 0;
}