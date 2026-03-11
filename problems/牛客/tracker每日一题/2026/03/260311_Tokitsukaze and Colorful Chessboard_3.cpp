#include <iostream>
#include <cmath>

void solve(){
  int a, b;
  std::cin >> a >> b;

  if(b > a){
    std::swap(a, b);
  }

  int n = std::ceil(std::sqrt(1. * (a + ((a & 1) ? a - 1 : a))));
  while((n * n + 1) / 2 < a || (n * n) / 2 < b){
    n++;
  }

  std::cout << n << "\n";
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