#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  
  int gcd = 0;
  for(int i = 0; i < n; i++){
    gcd = std::gcd(gcd,a[i]);
  }

  std::cout << 1LL*gcd*n << "\n";
}