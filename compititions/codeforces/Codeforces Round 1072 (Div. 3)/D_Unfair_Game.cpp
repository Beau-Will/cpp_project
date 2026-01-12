#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 n,k;
  std::cin >> n >> k;

  int d = 0;
  i64 tmp = n;
  while(tmp > 1){
    tmp >>= 1;
    d++;
  }

  auto comb = [&](i64 n,i64 k){
    if(k<0 || k>n){
      return 0LL;
    }
    if(k==0 || k==n){
      return 1LL;
    }

    i64 res = 1;
    for(int i = 1; i <= k; i++){
      res = res*(n-i+1)/i;
    }

    return res;
  };

  auto count = [&](int len,int x){
    if(x < 0){
      return 1LL<<(len-1);
    }

    i64 cnt = 0;
    for(int i = x; i <= len-1; i++){
      cnt += comb(len-1,i);
    }
    return cnt;
  };

  i64 ans = 0;

  for(int i = 1; i <= d; i++){
    int t = k-i+1;
    ans += count(i,t);
  }

  if(1+(d+1)-1 > k){
    ans++;
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