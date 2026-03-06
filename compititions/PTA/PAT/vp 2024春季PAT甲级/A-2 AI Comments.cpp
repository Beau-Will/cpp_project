#include <bits/stdc++.h>
/*
MID 86 74 68 72 60
T27346900:
rank4 4 3 2 1
*/
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::map<std::string, std::vector<int>> map;
  std::vector v(5, std::vector<int>());
  for (int i = 0; i < n; i++) {
    std::string s;
    std::vector<int> t(5);

    std::cin >> s;
    for (int i = 0; i < 5; i++) {
      std::cin >> t[i];
    }
    for (int i = 0; i < 5; i++) {
      map[s].push_back(t[i]);
      v[i].push_back(t[i]);
    }
  }

  for (int i = 0; i < 5; i++) {
    std::sort(v[i].begin(), v[i].end(), std::greater<>());
  }

  std::vector<int> mid(5);
  for (int i = 0; i < 5; i++) {
    if (v[i].size() & 1) {
      mid[i] = v[i][(v[i].size() + 1) / 2 - 1];
    } else {
      mid[i] = v[i][v[i].size() / 2 - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    std::string t;
    std::cin >> t;

    if (!map.count(t)) {
      std::cout << "Not Found\n";
      continue;
    }

    std::vector<std::array<int, 2>> pos, neg;
    for (int j = 0; j < 5; j++) {
      if (map[t][j] >= mid[j]) {
        pos.push_back({map[t][j] - mid[j], j + 1});
      } else {
        neg.push_back({mid[j] - map[t][j], j + 1});
      }
    }
    
    std::sort(pos.begin(), pos.end(), [&](const auto & t1, const auto & t2) {
      if (t1[0] != t2[0]) {
        return t1[0] > t2[0];
      }
      return t1[1] < t2[1];
    });
    std::sort(neg.begin(), neg.end(), [&](const auto & t1, const auto & t2) {
      if (t1[0] != t2[0]) {
        return t1[0] < t2[0];
      }
      return t1[1] < t2[1];
    });

    bool isFirst = true;
    for (int i = 0; i < pos.size(); i++) {
      if (isFirst) {
        isFirst = false;
      } else {
        std::cout << " ";
      }
      std::cout << pos[i][1];
    }
    for (int i = 0; i < neg.size(); i++) {
      if (isFirst) {
        isFirst = false;
      } else {
        std::cout << " ";
      }
      std::cout << "-" << neg[i][1];
    }
    std::cout << "\n";
  }

  return 0;
}