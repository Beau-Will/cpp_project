#include <bits/stdc++.h>

using i64 = long long;

void quick_sort(std::vector<int> &v,int l,int r){
  if(l>=r){
    return;
  }

  int i = l, j = r,x = v[l];
  while(i<j){
    while(v[j]>=x && i<j){
      j--;
    }
    v[i] = v[j];

    while(v[i]<=x && i<j){
      i++;
    }
    v[j] = v[i];
  }
  v[i] = x;

  quick_sort(v, l, i-1);
  quick_sort(v, i+1, r);
}

int main(){

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  quick_sort(a,0,n-1);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}