#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  std::string s;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    s += 'a' + a[i] - 1;
  }

  for (; q--;) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int k1, k2;
      std::string t1, t2;

      std::cin >> k1;
      for (int i = 0; i < k1; ++i) {
        int x;
        std::cin >> x;
        t1 += 'a' + x - 1;
      }

      std::cin >> k2;
      for (int i = 0; i < k2; ++i) {
        int x;
        std::cin >> x;
        t2 += 'a' + x - 1;
      }

      int pos;
      if ((pos = s.find(t1)) != std::string::npos) {
        s.replace(pos, k1, t2);
      }

    } else if (op == 2) {
      for (int i = 0; i < s.size() - 1; ++i) {
        int x1 = s[i] - 'a' + 1;
        int x2 = s[i + 1] - 'a' + 1;
        if ((x1 + x2) % 2 == 0) {
          int x3 = (x1 + x2) / 2;
          char c = 'a' + x3 - 1;
          std::string s1 = s.substr(0, i + 1);
          std::string s2 = s.substr(i + 1);
          s1 += c;
          s1 += s2;
          s = s1;
          ++i;
        }
      }
    } else { // op==3
      int l, r;
      std::cin >> l >> r;
      --l;

      std::reverse(s.begin() + l, s.begin() + r);
    }
  }

  for (int i = 0; i < s.size(); ++i) {
    std::cout << (s[i] - 'a' + 1) << " \n"[i + 1 == s.size()];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}