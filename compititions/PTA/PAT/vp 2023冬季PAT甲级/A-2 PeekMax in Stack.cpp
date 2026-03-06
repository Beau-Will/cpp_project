#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> stk;
  std::multiset<int> set;
  for (int i = 0; i < n; i++) {
    std::string op;
    std::cin >> op;

    if (op == "Push") {
      int x;
      std::cin >> x;

      stk.push_back(x);
      set.insert(x);
    } else if (op == "Pop") {
      if (stk.empty()) {
        std::cout << "ERROR\n";
      } else {
        int x = stk.back();
        stk.pop_back();
        auto it = set.lower_bound(x);
        set.erase(it);

        std::cout << x << "\n";
      }
    } else {
      if (stk.empty()) {
        std::cout << "ERROR\n";
      } else {
        std::cout << *set.rbegin() << "\n";
      }
    }
  }

  return 0;
}