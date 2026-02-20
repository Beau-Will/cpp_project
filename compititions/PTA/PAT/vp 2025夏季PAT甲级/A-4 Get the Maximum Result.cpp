#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<int> per(n);
  for (int i = 0; i < n; i++) {
    std::cin >> per[i];
  }
  std::sort(per.begin(), per.end());

  int ans = -1E9;

  do {
    std::vector<int> stk1;
    std::vector<char> stk2;
    int idx = 0;
    for (const auto& c : s) {
      if (c == '(') {
        stk2.push_back(c);
      } else if (c == ')') {
        if (stk2.size() && stk2.back() == '(') {
          stk2.pop_back();
          while (stk2.size() && stk2.back() != '(') {
            auto tmp1 = stk1.back();
            stk1.pop_back();
            auto tmp2 = stk1.back();
            stk1.pop_back();
            if (stk2.back() == '+') {
              stk1.push_back(tmp1 + tmp2);
            } else if (stk2.back() == '-') {
              stk1.push_back(tmp2 - tmp1);
            } else if (stk2.back() == '*') {
              stk1.push_back(tmp1 * tmp2);
            }
            stk2.pop_back();
          }
        }
      } else if (c == 'x') {
        stk1.push_back(per[idx++]);
      } else {
        stk2.push_back(c);
      }
    }
    ans = std::max(ans, stk1.back());
  } while (std::next_permutation(per.begin(), per.end()));

  std::cout << ans << "\n";
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