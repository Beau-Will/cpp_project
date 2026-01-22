#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int max = 0;
  i64 ans = 0;
  for(int i = 0; i < n; i++){
    max = std::max(max,a[i]);
    ans += max;
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      std::swap(a[i],a[j]);

      int max2 = 0;
      i64 ans2 = 0;
      for(int k = 0; k < n; k++){
        max2 = std::max(max2,a[k]);
        ans2 += max2;
      }
      ans = std::max(ans,ans2);

      std::swap(a[i],a[j]);
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
}