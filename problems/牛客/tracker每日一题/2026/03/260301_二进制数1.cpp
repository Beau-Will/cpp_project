#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 x;
  std::cin >> x;

  std::cout << __builtin_popcountll(x) << "\n";

  return 0;
}