#include <bits/stdc++.h>

using i64 = long long;

constexpr std::array d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
  return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int y, int m) {
  return d[m - 1] + (isLeap(y) && m == 2);
}

int getDay(int y, int m, int d) {
  int ans = 0;
  for (int i = 1970; i < y; i++) {
    ans += 365 + isLeap(i);
  }
  for (int i = 1; i < m; i++) {
    ans += daysInMonth(y, i);
  }
  ans += d;
  return (ans + 2) % 7 + 1;
}

void solve(){
  int y;
  std::cin >> y;

  int x = getDay(y,1,1);
  int ans = 0;

  for(int m = 1; m <= 12; m++){
    int t = daysInMonth(y,m);
    
    for(int d = 1; d <= t; d++){
      ans += (d == 1 || x == 1);
      x = x % 7 + 1;
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}