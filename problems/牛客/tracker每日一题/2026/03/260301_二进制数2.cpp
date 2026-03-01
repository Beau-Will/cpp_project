#include <iostream>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 x;
  std::cin >> x;

  int ans = 0;
  while(x){
    if(x & 1){
      ans++;
    }
    x >>= 1;
  }

  std::cout << ans << "\n";

  return 0;
}