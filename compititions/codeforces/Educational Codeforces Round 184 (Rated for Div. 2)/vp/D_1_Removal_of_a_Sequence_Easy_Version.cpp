#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  i64 x,y,k;
  std::cin >> x >> y >> k;

  i64 l = 1,r = 1E12+1;
  while(l < r){
    i64 mid = (l+r+1)/2;

    i64 p = mid-1;
    for(int i = 0; i < x; i++){
      p -= p/y;
    }

    if(p+1 <= k){
      l = mid;
    }else{
      r = mid-1;
    }
  }

  std::cout << (l==1E12+1?-1:l) << "\n";
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