#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pre(n+1),suf(n+2);
  for(int i = 1; i <= n; i++){
    pre[i] = std::gcd(pre[i-1],a[i]);
  }
  for(int i = n; i >= 1; i--){
    suf[i] = std::gcd(suf[i+1],a[i]);
  }

  i64 ans = 0;
  for(int i = 1; i < n; i++){
    ans += std::min(pre[i],suf[i]);
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}