#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  if(n==1 || n==2){
    std::cout << "-1\n";
    return;
  }

  if(n%2==1){
    for(int i = 2; i <= n; i++){
      std::cout << i << " ";
    }
    std::cout << "1\n";
  }else{
    std::vector<int> per(n+1);
    if(n%4==0){
      for(int i = 1; i+3 <= n; i+=4){
        per[i] = i+1;
        per[i+1] = i+3;
        per[i+2] = i;
        per[i+3] = i+2;
      }
    }else{
      for(int i = 1; i < n; i++){
        per[i] = i+1;
      }
      per[n] = 1;
      for(int i = 1; i < n; i++){
        if(i+per[i] == n+per[n]){
          std::swap(per[i],per[n]);
          break;
        }
      }
    }
    for(int i = 1; i <= n; i++){
      std::cout << per[i] << " \n"[i==n];
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}