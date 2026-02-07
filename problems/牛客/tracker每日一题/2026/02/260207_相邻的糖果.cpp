#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, x;
  std::cin >> n >> m >> x;

  int min = std::min(n, m);

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  i64 ans = 0, sum = 0;
  for(int i = 0; i < n; i++){
    sum += a[i];
    if(i >= m - 1 && sum > x){
      i64 t = sum - x;
      for(int j = i; j >= i - m + 1 && t; j--){
        if(t > a[j]){
          t -= a[j];
          sum -= a[j];
          ans += a[j];
          a[j] = 0;
        }else{
          sum -= t;
          ans += t;
          a[j] -= t;
          t = 0;
        }
      }
    }
    if(i >= m - 1){
      sum -= a[i - m + 1];
    }
  }

  std::cout << ans << "\n";

  return 0;
}