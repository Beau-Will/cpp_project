#include <bits/stdc++.h>

using i64 = long long;

void merge_sort(std::vector<int> &v,std::vector<int> &tmp,int l,int r){
  if(l>=r){
    return;
  }

  int mid = (l+r)>>1;

  merge_sort(v, tmp, l, mid);
  merge_sort(v, tmp, mid+1, r);

  int i = l,j = mid+1, k = 0;
  while(i<=mid && j<=r){
    if(v[i]<=v[j]){
      tmp[k++] = v[i++];
    }else{
      tmp[k++] = v[j++];
    }
  }

  while(i<=mid){
    tmp[k++] = v[i++];
  }
  while(j<=r){
    tmp[k++] = v[j++];
  }

  for(i = l, j = 0; i <= r; i++,j++){
    v[i] = tmp[j];
  }
}

int main(){

  int n;
  std::cin >> n;

  std::vector<int> a(n),tmp(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  merge_sort(a,tmp,0,n-1);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}