#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> a(n);
  std::set<std::string> has;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    has.insert(a[i]);
  }

  std::vector<std::string> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  int cur = 0, idx = 0;
  std::set<std::string> set;
  std::queue<std::string> q;
  for (; idx < std::min(n, m); idx++) {
    set.insert(a[idx]);
  }
  for (int i = 0; i < b.size(); i++) {
    q.push(b[i]);
  }

  while (set.size() && q.size()) {
    cur++;
    auto t = q.front();
    q.pop();

    if (set.count(t)) {
      set.erase(t);
      if (idx < n) {
        set.insert(a[idx++]);
      }
    } else {
      if (!has.count(t)) {
        std::cout << t << " is lost!\n";
      } else {
        q.push(t);
      }
    }
  }

  std::cout << cur << "\n";

  return 0;
}