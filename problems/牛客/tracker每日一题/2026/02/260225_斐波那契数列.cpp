#include <iostream>

constexpr int P = 1E9 + 7;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;
  std::cin >> k;

  if(k < 3){
    std::cout << "1\n";
    return 0;
  }

  int cur = 1, prev = 1;
  for(int i = 3; i <= k; i++){
    int tmp = (cur + prev) % P;
    prev = cur;
    cur = tmp;
  }

  std::cout << cur << "\n";

  return 0;
}