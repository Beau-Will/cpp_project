#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n+1),b(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> b[i];
  }

  std::vector<i64> dp1(n+1),dp2(n+1);
  for(int i = 1; i <= n; i++){
    dp1[i] = std::max(dp1[i-1]-a[i],b[i]-dp2[i-1]);
    dp2[i] = std::min(dp2[i-1]-a[i],b[i]-dp1[i-1]);
  }

  std::cout << dp1[n] << "\n";
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