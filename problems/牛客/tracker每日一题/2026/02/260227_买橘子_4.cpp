#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
 * 函数模板 exgcd
 * 可以处理 a, b, x, y为i64等情况
*/
template<typename T>
constexpr T exgcd(T a, T b, T& x, T& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  T d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  int a = 6, b = 8, x, y;
  auto gcd = exgcd(a, b, x, y);

  if(n % gcd){
    std::cout << "-1\n";
    return 0;
  }

  int k = n / gcd;
  x *= k;
  y *= k;

  int u = b / gcd;
  int v = a / gcd;

  int l = std::ceil(-1. * x / u);
  int r = y / v;

  if(l > r){
    std::cout << "-1\n";
    return 0;
  }

  std::cout << ((x + l * u) + (y - l * v)) << "\n";

  return 0;
}