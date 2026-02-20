#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::array<std::string, 5>> s(n);
  for (int i = 0; i < n; i++) {
    std::string t1, t2;
    std::cin >> t1 >> t2;
    s[i][0] = t1;
    s[i][1] = t2.substr(0, 3);
    s[i][2] = t2.substr(4, 2);
    s[i][3] = t2.substr(7, 2);
    s[i][4] = t2.substr(10);
  }

  std::set<std::array<int, 2>> set;
  std::map<std::string, int> cnt;
  for (int i = 0; i < n; i++) {
    auto [id, sday, shour, smin, ssec] = s[i];
    int day = std::stoi(sday);
    int hour = std::stoi(shour);
    int min = std::stoi(smin);
    int sec = std::stoi(ssec);

    if (hour >= 3 && hour <= 22) {
      continue;
    }
    if (hour == 23 && min == 0 && sec == 0) {
      continue;
    }

    if (hour == 23) {
      set.insert({day, day + 1});
      cnt[id]++;
    } else {
      set.insert({day - 1, day});
      cnt[id]++;
    }
  }

  std::cout << set.size() << "\n";
  if (set.size() == 0) {
    std::cout << "#\n";
    return;
  }

  int max = 0;
  std::vector<std::string> ans;
  for (const auto& [id, c] : cnt) {
    max = std::max(max, c);
  }
  for (const auto& [id, c] : cnt) {
    if (c == max) {
      ans.push_back(id);
    }
  }
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
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