#include <iostream>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m,n;
  std::cin >> m >> n;

  std::cout << __builtin_popcount(m ^ n) << "\n";
}