#include <iostream>
#include <vector>
#include <functional>

constexpr int P = 1E9 + 7;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;
  std::cin >> k;
  
  std::vector<int> f(k + 1);
  std::function<int(int)> dfs = [&](int n){
    if(n == 1 || n == 2){
      return 1;
    }
    if(f[n]){
      return f[n];
    }

    return f[n] = (dfs(n - 1) + dfs(n - 2)) % P;
  };

  std::cout << dfs(k) << "\n";

  return 0;
}