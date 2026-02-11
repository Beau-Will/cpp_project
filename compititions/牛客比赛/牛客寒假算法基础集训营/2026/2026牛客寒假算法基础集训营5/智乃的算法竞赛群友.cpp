#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 n, a, b;
  std::cin >> n >> a >> b;

  // a / 7 ? b / 2 ? (a + b) / 8
  i64 res1 = 0, res2 = 0, res3 = 0, res4 = 0;
  
  res1 += n / 2 * b;
  
  i64 t2 = n / 8;
  res2 += t2 * a + ((n - t2 * 6) / 2) * b;

  i64 t3 = n / 7;
  if(t3 * 8 <= n){
    res3 += t3 * a + ((n - t3 * 6) / 2) * b;
  }else{
    res3 += t3 * a + (n - t3 * 7) * b;
  }

  if((t2 + 1) * 7 <= n){
    res4 += (t2 + 1) * a + (n - (t2 + 1) * 7) * b;
  }

  i64 ans = std::max({res1, res2, res3, res4});

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}