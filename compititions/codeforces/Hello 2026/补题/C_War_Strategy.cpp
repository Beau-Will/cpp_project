#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m,k;
  std::cin >> n >> m >> k;

  if(k-1 < n-k){
    k = n+1-k;
  }

  auto f = [&](int a,int b){
    return a+b+std::max(a,b)-1;
  };

  int a = 0,b = 0;
  for(;;){
    if(b<n-k && f(a,b+1) <= m){
      b++;
    }

    if(a<k-1 && f(a+1,b) <= m){
      a++;
    }else{
      break;
    }
  }

  std::cout << a+b+1 << "\n";
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