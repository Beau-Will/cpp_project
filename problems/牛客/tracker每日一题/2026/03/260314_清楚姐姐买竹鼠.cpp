#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, x;
  std::cin >> a >> b >> x;

  auto cal = [&](int tar){
    int cnt = tar / 3;
    int rest = tar % 3;
    return std::min({1LL * a * tar, 1LL * b * cnt + 1LL * a * rest, 1LL * b * (cnt + 1)});
  };

  std::cout << cal(x) << "\n";

  return 0;
}