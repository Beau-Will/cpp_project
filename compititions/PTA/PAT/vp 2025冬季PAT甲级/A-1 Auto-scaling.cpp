#include <bits/stdc++.h>

using i64 = long long;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 n,T,S,s;
  std::cin >> n >> T >> S >> s;

  std::vector<int> c(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> c[i];
  }

  std::vector<int> C(n+1);
  int sum = 0;
  for(int i = 1; i <= S-1; i++){
    sum += c[i]/S;
  }
  for(int i = 1; i <= n; i++){
    if(i < S){
      C[i] = c[i];
    }else{
      sum += c[i]/S;
      sum -= c[i-S]/S;
      C[i] = sum;
    }
  }

  int last = -1;
  for(int i = 1; i <= n; i++){
    if(i < s){
      std::cout << std::max(1LL,C[i]/T) << " \n"[i==n];
      last = std::max(1LL,C[i]/T);
    }else{
      int diff = C[i]-C[i-s+1];
      int t = diff/s;
      if(t >= T*2){
        std::cout << "*" << last+diff/(s*T) << " \n"[i==n];
        last = last+diff/(s*T);
      }else{
        std::cout << std::max(1LL,C[i]/T) << " \n"[i==n];
        last = std::max(1LL,C[i]/T);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << C[i] << " \n"[i==n];
  }
}