#include <iostream>
#include <vector>

constexpr int P = 10007;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x, n;
  std::cin >> x >> n;

  std::vector g(10, std::vector<bool>(10));
  for(int i = 0; i < 10; i++){
    g[i][i] = true;
  }

  for(int i = 0; i < n; i++){
    int u, v;
    std::cin >> u >> v;

    g[u][v] = true;
  }

  for(int k = 0; k < 10; k++){
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        if(!g[i][j] && g[i][k] && g[k][j]){
          g[i][j] = true;
        }
      }
    }
  }

  std::vector<int> cnt(10);
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(g[i][j]){
        cnt[i]++;
      }
    }
  }

  int ans = 1;
  std::string s = std::to_string(x);
  for(const auto& c : s){
    int t = c ^ 48;
    ans = (1LL * ans * cnt[t]) % P;
  }

  std::cout << ans << "\n";

  return 0;
}