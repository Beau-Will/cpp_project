#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::vector<std::array<int,3>> a(3);
  for(int i = 0; i < 3; i++){
    std::cin >> a[i][0] >> a[i][1];
    a[i][2] = i+1;
  }

  std::sort(a.begin(),a.end());

  std::cout << a[1][2] << "\n";
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