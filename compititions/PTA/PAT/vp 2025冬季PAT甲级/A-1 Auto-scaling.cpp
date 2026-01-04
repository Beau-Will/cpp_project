#include <bits/stdc++.h>

using i64 = long long;

/*
样例输入：
20 100 6 3
0 10 50 110 360 200 100 130 180 200 1800 2500 200 1200 900 300 280 150 100 10

样例输出：
1 1 1 1 3 1 1 1 1 1 4 *6 8 10 11 11 8 5 4 2
0 10 50 110 360 120 136 156 178 193 433 816 833 1012 1132 1149 895 504 487 288
*/

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,T,S,s;
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
      std::cout << std::max(1,C[i]/T) << " \n"[i==n];
      last = std::max(1,C[i]/T);
    }else{
      int diff = C[i]-C[i-s+1];
      int t = diff/s;
      if(t >= T*2){
        std::cout << "*" << last+diff/(s*T) << " \n"[i==n];
        last = last+diff/(s*T);
      }else{
        std::cout << std::max(1,C[i]/T) << " \n"[i==n];
        last = std::max(1,C[i]/T);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << C[i] << " \n"[i==n];
  }
}