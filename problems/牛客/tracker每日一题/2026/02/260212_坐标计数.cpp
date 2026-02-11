#include <iostream>

void solve(){
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::cout << 1LL * (x2 - x1 + 1) * (y2 - y1 + 1) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}