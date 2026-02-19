#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int a, b;
  std::cin >> a >> b;

  std::string t;
  if(a == b){
    for(int i = 1; i <= a; i++){
      t += "10";
    }
  }else{
    char c0 = '0', c1 = '1';
    if(a < b){
      std::swap(a, b);
      std::swap(c0, c1);
    }
    int x = a / (b + 1);
    int k = a % (b + 1);
    for(int i = 1; i <= b + 1; i++){
      t += std::string(x + (k > 0 ? 1 : 0), c0);
      if(k > 0){
        k--;
      }
      t += c1;
    }
    t.pop_back();
  }

  std::cout << t << "\n";
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