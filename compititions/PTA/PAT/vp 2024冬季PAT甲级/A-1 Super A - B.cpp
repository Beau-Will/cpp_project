#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string sa, sb;
  std::cin >> sa >> sb;

  while (sa.back() == '0') {
    sa.pop_back();
  }
  while (sb.back() == '0') {
    sb.pop_back();
  }

  bool isNeg = (sa < sb);

  int lena = sa.size();
  int lenb = sb.size();

  if (lena < lenb) {
    for (int i = 0; i < lenb - lena; i++) {
      sa += '0';
    }
  } else if (lena > lenb) {
    for (int i = 0; i < lena - lenb; i++) {
      sb += '0';
    }
  }

  if (isNeg) {
    std::swap(sa, sb);
  }

  std::string ans = "0.";
  for (int i = 2; i < sa.size(); i++) {
    int d = sa[i] - sb[i];
    if (d < 0) {
      d += 10;
      for (int j = i - 1; j >= 2; j--) {
        if (ans[j] == '0') {
          ans[j] = '9';
        } else {
          ans[j]--;
          break;
        }
      }
      ans += char('0' + d);
    } else {
      ans += char('0' + d);
    }
  }

  while (ans.back() == '0') {
    ans.pop_back();
  }

  std::cout << (isNeg ? "-" : "") << ans << "\n";

  return 0;
}