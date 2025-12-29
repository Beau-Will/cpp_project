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

  std::vector<int> b(n*2+1);
  for(int i = 1; i <= n; i++){
    b[i] = a[i];
    b[i+n] = a[i];
  }

  std::vector<i64> pre(1);
  std::partial_sum(b.begin()+1,b.end(),std::back_inserter(pre));

  auto dp1 = std::vector(n*2+1,std::vector(n*2+1,inf2));
  auto dp2 = std::vector(n*2+1,std::vector(n*2+1,-inf2));

  for(int l = 1; l <= n*2; l++){
    dp1[l][l] = 0;
    dp2[l][l] = 0;
  }

  for(int len = 2; len <= n; len++){
    for(int l = 1; l+len-1 <= n*2; l++){
      int r = l+len-1;

      //枚举分界点mid
      //[l,mid],[mid+1,r]
      for(int mid = l; mid < r; mid++){
        dp1[l][r] = std::min(dp1[l][r],dp1[l][mid]+dp1[mid+1][r]+pre[r]-pre[l-1]);
        dp2[l][r] = std::max(dp2[l][r],dp2[l][mid]+dp2[mid+1][r]+pre[r]-pre[l-1]);
      }
    }
  }

  i64 min = inf2,max = -inf2;
  for(int l = 1; l+n-1 <= n*2; l++){
    int r = l+n-1;
    min = std::min(min,dp1[l][r]);
    max = std::max(max,dp2[l][r]);
  }

  std::cout << min << "\n" << max << "\n";
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

  return 0;
}