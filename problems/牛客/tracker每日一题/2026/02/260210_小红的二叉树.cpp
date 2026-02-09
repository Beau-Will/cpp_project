#include <iostream>

using i64 = long long;

constexpr int P = 1'000'000'007;

template<typename T = int>
T quick_power(T a, T b){
  T res = 1 % P;
  for(; b; a = static_cast<i64>(a) * a % P, b >>= 1){
    if(b & 1){
      res = static_cast<i64>(res) * a % P;
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  if(n == 1){
    std::cout << "0\n";
    return 0;
  }

  std::cout << ((quick_power(2, n - 1) * 3LL % P) - 5 + P) % P << "\n";

  return 0;
}