#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

std::vector<i64> a(1),b(30),c(30);

void solve(){
  int x,y;
  std::cin >> x >> y;

  for(int i = 1; i <= 22; i++){
    if((x>=b[i] && y>=c[i]) || (x>=c[i] && y>=b[i])){
      continue;
    }
    std::cout << i-1 << "\n";
    return;
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 tmp = 1;
  while(tmp <= 2000000){
    a.push_back(tmp);
    tmp *= 2;
  }

  for(int i = 1; i <= 22; i++){
    if(i&1){
      b[i] = (i-2>=0?b[i-2]:0)+a[i];
      c[i] = c[i-1];
    }else{
      c[i] = (i-2>=0?c[i-2]:0)+a[i];
      b[i] = b[i-1];
    }
  }

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}