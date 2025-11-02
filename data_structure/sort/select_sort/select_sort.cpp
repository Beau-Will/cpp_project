#include <bits/stdc++.h>

using i64 = long long;

void select_sort(std::vector<int> &v,int l,int r){
  for(int i = l; i < r; ++i){
    int idx = i;
    for(int j = i+1; j <= r; ++j){
      if(v[j]<v[idx]){
        idx = j;
      }
    }
    std::swap(v[i],v[idx]);
  }
}

int main(){

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  select_sort(a,0,n-1);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}