#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int s,k,m;
  std::cin >> s >> k >> m;

  int ans = 0;
  if(k >= s){
    int t = m/k*k;
    ans = std::max(0,s-(m-t));
  }else{
    int rest = s-k;
    int cnt = m/k;
    int t = cnt*k;

    if(cnt & 1){
      ans = std::max(0,k-(m-t));
    }else{
      ans = std::max(0,s-(m-t));
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