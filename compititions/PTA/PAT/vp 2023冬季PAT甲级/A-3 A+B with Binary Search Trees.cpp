#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t1;
  std::cin >> t1;

  int root1 = -1;
  std::vector<i64> w1(t1);
  std::vector<int> par1(t1);
  for (int i = 0; i < t1; i++) {
    std::cin >> w1[i] >> par1[i];
  }

  std::vector<int> left1(t1, -1), right1(t1, -1);
  for (int i = 0; i < t1; i++) {
    if (par1[i] == -1) {
      root1 = i;
      continue;
    }
    int parw = w1[par1[i]];
    if (w1[i] < parw) {
      left1[par1[i]] = i;
    } else {
      right1[par1[i]] = i;
    }
  }

  int t2;
  std::cin >> t2;

  int root2 = -1;
  std::vector<i64> w2(t2);
  std::vector<int> par2(t2 );
  for (int i = 0; i < t2; i++) {
    std::cin >> w2[i] >> par2[i];
  }

  std::vector<int> left2(t2, -1), right2(t2, -1);
  for (int i = 0; i < t2; i++) {
    if (par2[i] == -1) {
      root2 = i;
      continue;
    }
    int parw = w2[par2[i]];
    if (w2[i] < parw) {
      left2[par2[i]] = i;
    } else {
      right2[par2[i]] = i;
    }
  }

  i64 n;
  std::cin >> n;

  std::vector<std::array<i64, 2>> res;
  std::map<i64, int> cnt1, cnt2;
  for (int i = 0; i < t1; i++) {
    cnt1[w1[i]]++;
  }
  for (int i = 0; i < t2; i++) {
    cnt2[w2[i]]++;
  }
  for (const auto& [u, v] : cnt1) {
    if (cnt2.count(n - u)) {
      res.push_back({u, n - u});
    }
  }

  if (res.size()) {
    std::cout << "true\n";
    for (int i = 0; i < res.size(); i++) {
      std::cout << n << " = " << res[i][0] << " + " << res[i][1] << "\n";
    }
  } else {
    std::cout << "false\n";
  }

  bool isFirst1 = true;
  auto pre1 = [&](auto&& self, int u) ->void {
    if (isFirst1) {
      isFirst1 = false;
    } else {
      std::cout << " ";
    }
    std::cout << w1[u];

    if (~left1[u]) {
      self(self, left1[u]);
    }
    if (~right1[u]) {
      self(self, right1[u]);
    }
  };

  pre1(pre1, root1);
  std::cout << "\n";

  bool isFirst2 = true;
  auto pre2 = [&](auto&& self, int u) ->void {
    if (isFirst2) {
      isFirst2 = false;
    } else {
      std::cout << " ";
    }
    std::cout << w2[u];

    if (~left2[u]) {
      self(self, left2[u]);
    }
    if (~right2[u]) {
      self(self, right2[u]);
    }
  };

  pre2(pre2, root2);
  std::cout << "\n";

  return 0;
}