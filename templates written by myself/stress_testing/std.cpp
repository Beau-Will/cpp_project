#include <bits/stdc++.h>

using i64 = long long;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  i64 ans = 0;
  std::vector<int> tmp(n);

  std::function<void(int,int)> merge_sort = [&](int l,int r)->void {
    if(l >= r){
      return;
    }

    int mid = (l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);

    int k = 0,i = l,j = mid+1;
    while(i <= mid && j <= r){
      if(a[i] <= a[j]){
        tmp[k++] = a[i++];
      }else{
        tmp[k++] = a[j++];
        ans += mid-i+1;
      }
    }

    while(i <= mid){
      tmp[k++] = a[i++];
    }
    while(j <= r){
      tmp[k++] = a[j++];
    }

    for(i = l,j = 0; i <= r; i++,j++){
      a[i] = tmp[j];
    }
  };

  merge_sort(0,n-1);

  std::cout << ans << "\n";
}