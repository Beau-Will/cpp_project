#include <iostream>
#include <vector>
#include <iomanip>

void solve() {
  int n,m;
  while(std::cin >> n >> m){
    std::vector<std::vector<int>> v(n,std::vector<int>(m));
    std::vector<double> sum(m,0);

    for(int i = 0; i < n; i++){
      double s = 0;
      for(int j = 0; j < m; j++){
        std::cin >> v[i][j];
        s += v[i][j];
        sum[j] += v[i][j];
      }
      std::cout << std::fixed << std::setprecision(2) << 1.*s/m << " \n"[i+1==n];
    }

    for(int i = 0; i < m; i++){
      std::cout << std::fixed << std::setprecision(2) << 1.*sum[i]/n << " \n"[i+1==m];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
      bool is_good = true;
      for(int j = 0; j < m; j++){
        if(1LL*v[i][j]*n<sum[j]){
          is_good = false;
          break;
        }
      }
      if(is_good){
        ans++;
      }
    }

    std::cout << ans << "\n\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}