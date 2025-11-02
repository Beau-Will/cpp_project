#include <bits/stdc++.h>

using i64 = long long;

void insert_sort(std::vector<int> &v){
  for(int i = 1; i < v.size(); ++i){
    if(v[i]<v[i-1]){//v[0]~v[i-1]已经升序，若v[i]<v[i-1]，则需要插入
      int t = v[i];
      int j;
      for(j = i-1; v[j] > t && j >= 0; --j){//找到第一个v[j]<=t的位置
        v[j+1] = v[j];
      }
      v[j+1] = t;
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

  insert_sort(a);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}