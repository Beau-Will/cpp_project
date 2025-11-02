#include <bits/stdc++.h>

using i64 = long long;

void bubble_sort(std::vector<int> &v){
  for(int i = 0; i < v.size()-1; ++i){
    bool isok = true;
    for(int j = v.size()-1; j > i; --j){
      if(v[j] < v[j-1]){
        std::swap(v[j],v[j-1]);
        isok = false;
      }
    }
    if(isok){
      return;
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

  bubble_sort(a);

  for(int i = 0; i < n; ++i){
    std::cout << a[i] << " \n"[i+1==n];
  }

  return 0;
}