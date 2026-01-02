#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n+1),suf(n+2);
  for(int i = 1; i <= n; i++){
    if(i == 1){
      pre[i] = pre[i-1]+a[i];
    }else{
      pre[i] = pre[i-1]+std::abs(a[i]);
    }
  }

  for(int i = n; i >= 1; i--){
    suf[i] = suf[i+1]-a[i];
  }

  i64 ans = -inf2;
  for(int i = 1; i <= n; i++){
    ans = std::max(ans,pre[i-1]+suf[i+1]);
  }

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