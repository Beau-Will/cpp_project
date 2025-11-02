#include <bits/stdc++.h>

using i64 = long long;

void shell_sort(std::vector<int> &v){
  for(int di = v.size()/2; di >= 1; di>>=1){//增量di
    for(int i = di; i < v.size(); ++i){
      if(v[i] < v[i-di]){
        int t = v[i];
        int j;
        for(j = i-di; j >= 0 && v[j]>t; j-=di){
          v[j+di] = v[j];
        }
        v[j+di] = t;
      }
    }
  }
}

int main(){

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  shell_sort(a);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}