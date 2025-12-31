#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  if(n<=2 || m<=2){
    std::cout << "1\n";
    return;
  }

  // 1 5 9 ...
  // 3 7 11 ...

  i64 ans = 1;
  i64 row = (n+1)/2; // 1 2 ...
  i64 col = (m+1)/2; // 1 2 ...

  i64 sum = 0;
  if(row & 1){
    sum += ((row+1)/2)*((col+1)/2);
    sum += (row/2)*(col/2);
  }else{
    sum += (row/2)*((col+1)/2);
    sum += (row/2)*(col/2);
  }

  ans = std::max(ans,sum);

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}