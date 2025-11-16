#include <bits/stdc++.h>

//求1996^(1995^1994)

int quick_power(int a,int b,int p){
  int res = 1;
  for(; b; b >>= 1,a = a*a%p){
    if(b&1){
      res = res*a%p;
    }
  }
  return res;
}

int main(){

  std::cout << quick_power(1996, quick_power(1995, 1994, 7), 7);

  return 0;
}