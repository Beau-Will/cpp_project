#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int ans = inf;
  for(int i = 0; i <= n / 8; i++){
    if((n - i * 8) % 6){
      continue;
    }
    int j = (n - i * 8) / 6;
    ans = std::min(ans, i + j);
  }

  std::cout << (ans == inf ? -1 : ans) << "\n";

  return 0;
}