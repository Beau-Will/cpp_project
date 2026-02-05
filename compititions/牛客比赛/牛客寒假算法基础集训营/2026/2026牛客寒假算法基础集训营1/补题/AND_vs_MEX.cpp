#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  i64 l, r;
  std::cin >> l >> r;

  auto count = [&](i64 x){
    for(int i = 31; i >= 0; i--){
      if((x >> i) & 1){
        return i;
      }
    }
    return -1;
  };

  int cntl = count(l), cntr = count(r);
  if(cntl == -1){
    std::cout << r + 1 << "\n";
  }else if(cntr == cntl){
    std::cout << "0\n";
  }else if(cntr > (cntl + 1)){
    std::cout << r + 1 << "\n";
  }else{
    i64 x = 1LL << cntr;
    i64 t = r - x + 1;
    i64 low = 0;
    for(int i = cntl; i >= 0; i--){
      if((l >> i) & 1){
        low |= (1LL << i);
      }else{
        break;
      }
    }
    if(low <= t){
      std::cout << r + 1 << "\n";
    }else{
      std::cout << t << "\n";
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}