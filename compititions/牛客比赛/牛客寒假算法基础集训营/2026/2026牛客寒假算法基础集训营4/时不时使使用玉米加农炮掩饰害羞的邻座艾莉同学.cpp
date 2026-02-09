#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

constexpr std::array dx = {-1, -1, 0, 1, 1, 1, 0, -1, -2, 0, 2, 0, 0};
constexpr std::array dy = {0, 1, 1, 1, 0, -1, -1, -1, 0, 2, 0, -2, 0};

void solve(){
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector a(n, std::vector<i64>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      std::cin >> a[i][j];
    }
  }

  std::vector s(n, std::vector<i64>(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < 13; k++){
        int u = i + dx[k], v = j + dy[k];
        if(u < 0 || u >= n || v < 0 || v >= m){
          continue;
        }
        s[i][j] += a[u][v];
      }
    }
  }

  i64 maxi = -1, maxj = -1, max = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(s[i][j] > max){
        max = s[i][j];
        maxi = i;
        maxj = j;
      }
    }
  }
  // std::cout << max << " " << maxi << " " << maxj << "\n";
  // std::cout << "???\n";

  for(int qi = 0; qi < q; qi++){
    int x, y, z;
    std::cin >> x >> y >> z;
    x--;
    y--;

    std::vector<std::array<i64, 3>> ans;
    ans.push_back({max, maxi, maxj});

    for(int k = 0; k < 13; k++){
      int u = x + dx[k], v = y + dy[k];
      if(u < 0 || u >= n || v < 0 || v >= m){
        continue;
      }
      s[u][v] += z;
      ans.push_back({s[u][v], u, v});
    }
    // a[x][y] += z;

    std::sort(ans.begin(), ans.end());

    // for(int i = 0; i < ans.size(); i++){
    //   for(int j = 0; j < 3; j++){
    //     std::cout << ans[i][j] << " \n"[j + 1 == 3];
    //   }
    // }
    // std::cout << "---\n";

    auto [_, i, j] = ans.back();
    max = _;
    maxi = i;
    maxj = j;

    std::cout << maxi + 1 << " " << maxj + 1 << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}