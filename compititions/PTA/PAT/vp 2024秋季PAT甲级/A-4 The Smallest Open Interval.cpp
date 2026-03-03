#include <bits/stdc++.h>

constexpr int inf = 2E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::set<int> set;
  set.insert(-inf);
  set.insert(inf);

  std::string op;
  while (std::cin >> op) {
    if (op == "E") {
      break;
    }
    int x;
    std::cin >> x;

    if (op == "I") {
      set.insert(x);
    } else {
      int r = *set.upper_bound(x);
      int l = *(--set.lower_bound(x));

      std::cout << "(" << (l == -inf ? "-inf" : std::to_string(l));
      std::cout << ", " << (r == inf ? "+inf" : std::to_string(r)) << ")\n";
    }
  }

  return 0;
}