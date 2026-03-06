#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> post(n), in(n);
  for (int i = 0; i < n; i++) {
    std::cin >> post[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> in[i];
  }

  std::map<int, int> map;
  for (int i = 0; i < n; i++) {
    map[in[i]] = i;
  }

  std::vector<int> left(n + 1), right(n + 1);
  std::function<int(int, int, int, int)> build = [&](int i1, int j1, int i2, int j2) {
    if (i1 > j1) {
      return 0;
    }
    int rt = post[j1];
    int idx = map[rt];
    int left_len = idx - i2;

    int leftrt = build(i1, i1 + left_len - 1, i2, idx - 1);
    int rightrt = build(i1 + left_len, j1 - 1, idx + 1, j2);

    left[rt] = leftrt;
    right[rt] = rightrt;

    return rt;
  };

  build(0, n - 1, 0, n - 1);

  int nl = 0, nr = 0;
  for (int i = 1; i <= n; i++) {
    if (left[i] && !right[i]) {
      nl++;
    } else if (right[i] && !left[i]) {
      nr++;
    }
  }

  std::cout << nl - nr << " = " << nl << " - " << nr << "\n";

  return 0;
}