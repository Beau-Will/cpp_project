#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::vector a(3, std::vector<int>(3));
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      std::cin >> a[i][j];
    }
  }

  std::set<int> set;
  std::vector<int> row(3), col(3);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      row[i] += a[i][j];
      col[j] += a[i][j];
      set.insert(a[i][j]);
    }
  }

  int t = row[0];
  if(set.size() != 9 || t != row[0] || t != row[1] || t != row[2] || t != col[0] || t != col[1] || t != col[2]){
    std::cout << "No\n";
    return;
  }
  if(a[0][0] + a[1][1] + a[2][2] != t || a[0][2] + a[1][1] + a[2][0] != t){
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
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