#include <iostream>
#include <vector>
#include <numeric>

using i64 = long long;

void solve(){
  i64 n;
  std::cin >> n;

  for(i64 a = n / 2; ; a--){
    i64 b = n - a;
    if(std::gcd(a, b) == 1){
      std::cout << a << " " << b << "\n";
      break;
    }
  }
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