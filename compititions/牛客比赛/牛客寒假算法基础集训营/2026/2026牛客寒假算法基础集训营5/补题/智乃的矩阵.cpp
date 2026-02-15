#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector a(n, std::vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin >> a[i][j];
    }
  }

  i64 sum = 0;
  for(int i = 0; i < n; i++){
    sum += std::accumulate(a[i].begin(), a[i].end(), 0LL);
  }

  if(sum % (1LL * n * n)){
    std::cout << "No\n";
    return;
  }

  sum /= (1LL * n * n);

  std::vector<i64> row(n), col(n);
  i64 t = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      row[i] += a[i][j];
      col[j] += a[i][j];

      if((i + j) & 1){
        t -= a[i][j];
      }else{
        t += a[i][j];
      }
    }
  }

  if(n % 2 == 0 && t){
    std::cout << "No\n";
    return;
  }

  if((n & 1) && t != sum){
    std::cout << "No\n";
    return;
  }

  for(int i = 0; i < n; i++){
    if(row[i] % 2 != (n * sum) % 2){
      std::cout << "No\n";
      return;
    }
    if(col[i] % 2 != (n * sum) % 2){
      std::cout << "No\n";
      return;
    }
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