#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m,k;
  std::cin >> n >> m >> k;

  auto f = [&](int a,int b){
    return a+b+std::max(a,b)-1;
  };

  int ans = 0;
  for(int i = 0; i < k; i++){
    int l = -1,r = n-k+1;
    while(r-l > 1){
      int mid = (l+r)/2;
      if(f(i,mid) <= m){
        l = mid;
      }else{
        r = mid;
      }
    }
    if(l != -1){
      if(i+l > ans){
        ans = i+l;
      }
    }
  }

  std::cout << ans+1 << "\n";
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