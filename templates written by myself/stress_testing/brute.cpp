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
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(a[i] > a[j]){
        ans++;
      }
    }
  }

  std::cout << ans << "\n";
}