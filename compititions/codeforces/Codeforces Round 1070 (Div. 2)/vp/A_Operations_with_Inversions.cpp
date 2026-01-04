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

  std::vector<int> max(n+1);
  for(int i = 1; i <= n; i++){
    max[i] = std::max(max[i-1],a[i]);
  }

  int ans = 0;
  for(int i = n; i >= 1; i--){
    if(max[i-1] > a[i]){
      ans++;
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
  for(; T--;){
    solve();
  }

  return 0;
}