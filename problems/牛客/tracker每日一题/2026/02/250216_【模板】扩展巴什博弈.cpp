#include <iostream>

void solve(){
  int n, l, r;
  std::cin >> n >> l >> r;

  std::cout << (n % (l + r) >= l ? "YES\n" : "NO\n");
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