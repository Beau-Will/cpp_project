#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n,a1,m;
  std::cin >> n >> a1 >> m;

  std::vector<int> a(n+1);
  a[1] = a1;
  for(int i = 2; i <= n; i++){
    a[i] = (a[i-1]+7*i)%m;
  }

  std::vector<i64> b(n+1);
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j += i){
      b[j] += a[i];
    }
  }

  i64 ans = 0;
  for(int i = 1; i <= n; i++){
    ans ^= b[i];
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