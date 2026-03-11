#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

std::vector<std::array<int, 2>> v(45001);

void solve(){
  int a, b;
  std::cin >> a >> b;

  if(b > a){
    std::swap(a, b);
  }

  std::cout << std::lower_bound(v.begin(), v.end(), std::array{a, b}) - v.begin() << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  for(int i = 1; i <= 45000; i++){
    v[i] = {(i * i + 1) / 2, (i * i) / 2};
  }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}