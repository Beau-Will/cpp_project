#include <bits/stdc++.h>

using i64 = long long;

void binary_insert_sort(std::vector<int> &v){
  for(int i = 1; i < v.size(); ++i){
    if(v[i]<v[i-1]){//v[0]~v[i-1]已经升序，若v[i]<v[i-1]，则需要插入
      int t = v[i];
      //二分找到第一个大于t的位置
      int idx = std::upper_bound(v.begin(),v.begin()+i,t)-v.begin();
      for(int j = i-1; j >= idx; --j){
        v[j+1] = v[j];
      }
      v[idx] = t;
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

  binary_insert_sort(a);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}