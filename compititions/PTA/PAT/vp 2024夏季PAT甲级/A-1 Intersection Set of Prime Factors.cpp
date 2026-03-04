#include <bits/stdc++.h>

constexpr int inf = 2E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::string sn = std::to_string(n);
  int max = 0, ans = inf;

  auto get = [&](int x) {
    std::vector<int> res;
    for (int i = 2; i <= x / i; i++) {
      while (x % i == 0) {
        res.push_back(i);
        x /= i;
      }
    }
    if (x != 1) {
      res.push_back(x);
      x = 1;
    }
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
  };

  auto set1 = get(n);

  for (int i = 0; i < sn.size(); i++) {
    for (int j = i + 1; j < sn.size(); j++) {
      if (sn[i] == sn[j]) {
        continue;
      }
      std::string t = sn;
      std::swap(t[i], t[j]);

      int tmp = std::stoi(t);
      auto set2 = get(tmp);

      std::vector<int> set3;
      std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(set3));

      if (set3.size() > max || (set3.size() == max && tmp < ans)) {
        max = set3.size();
        ans = tmp;
      }
    }
  }

  std::cout << max << " " << ans << "\n";

  return 0;
}