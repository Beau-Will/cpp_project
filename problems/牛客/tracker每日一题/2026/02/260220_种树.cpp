#include <iostream>
#include <vector>
#include <array>
#include <functional>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::array<int, 2>> child(n + 1);
  int m = 0;
  for(int i = 1; i <= n; i++){
    auto& [ls, rs] = child[i];
    std::cin >> ls >> rs;
    if(ls){
      m++;
    }
  }

  std::vector<int> w(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> w[i];
  }

  m = (m + 1) / 2;
  std::function<void(int, int)> dfs = [&](int u, int d){
    auto [ls, rs] = child[u];
    if(ls == 0){
      return;
    }
    dfs(ls, d + 1);
    dfs(rs, d + 1);
    if(d <= m){
      w[u] = std::max(w[ls], w[rs]);
    }else{
      w[u] = std::min(w[ls], w[rs]);
    }
  };

  dfs(1, 1);

  std::cout << w[1] << "\n";

  return 0;
}