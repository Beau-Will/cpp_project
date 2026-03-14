#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m, q;
  std::cin >> n >> m >> q;

  int curn = n, curm = m;
  for(int qi = 0; qi < q; qi++){
    int op, x;
    std::cin >> op >> x;

    if(op == 1){
      std::cout << x * curm << "\n";
      curn -= x;
    }else{
      std::cout << x * curn << "\n";
      curm -= x;
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}