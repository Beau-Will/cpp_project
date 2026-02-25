#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> suf1(n + 2), suf2(n + 2);
  for(int i = n; i >= 1; i--){
    suf1[i] = suf1[i + 1] + a[i];
    suf2[i] = suf2[i + 1] + (a[i] & 1);
  }

  i64 ans = 0;
  for(int i = 1; i <= n; i++){
    int sufOdd = suf2[i + 1];
    int sufEven = (n - i) - suf2[i + 1];

    if(a[i] & 1){
      ans += (1LL * (n - i) * a[i] + suf1[i + 1] - sufEven) / 2;
    }else{
      ans += (1LL * (n - i) * a[i] + suf1[i + 1] - sufOdd) / 2;
    }
  }

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