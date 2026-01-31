#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  if(n == 1 || n == 2 || n == 4){
    std::cout << "-1\n";
    return;
  }

  if(n & 1){
    for(int i = 1; i <= (n+1)/2; i++){
      std::cout << i << " ";
    }
    for(int i = n/2; i >= 1; i--){
      std::cout << i << " \n"[i==1];
    }

    return;
  }

  std::cout << "1 2 1 ";
  for(int i = 1; i <= (n-3+1)/2; i++){
    std::cout << i << " ";
  }
  for(int i = (n-3)/2; i >= 1; i--){
    std::cout << i << " \n"[i==1];
  }
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