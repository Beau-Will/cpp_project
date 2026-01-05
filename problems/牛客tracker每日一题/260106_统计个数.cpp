#include <iostream>
#include <vector>
#include <numeric>

void solve(){
  int n,m;
  std::cin >> n >> m;

  auto g = std::vector(n+1,std::vector<int>(n+1));
  for(int i = 0; i < m; i++){
    int u,v;
    std::cin >> u >> v;

    g[u][v] = 1;
    g[v][u] = 1;
  }

  int cnt1 = 0,cnt2 = 0;
  for(int a = 1; a <= n; a++){
    for(int b = 1; b <= n; b++){
      if(b==a || g[a][b]==0){
        continue;
      }
      for(int c = 1; c <= n; c++){
        if(c==a || c==b || g[b][c]==0){
          continue;
        }
        cnt2++;

        if(g[c][a]){
          cnt1++;
        }
      }
    }
  }

  if(cnt1 == 0){
    std::cout << "0/1\n";
    return;
  }

  int gcd = std::gcd(cnt1,cnt2);

  std::cout << cnt1/gcd << "/" << cnt2/gcd << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }
}