#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  i64 k;
  std::cin >> n >> k;

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n + 1);
  std::partial_sum(a.begin(), a.end(), pre.begin());

  i64 ans = 0;
  for(int i = 0; i < n; i++){
    int lo = i + 1, hi = n;
    while(lo < hi){
      int mid = (lo + hi) >> 1;
      if(pre[mid] - pre[i] >= k){
        hi = mid;
      }else{
        lo = mid + 1;
      }
    }
    if(pre[lo] - pre[i] >= k) ans += n + 1 - lo;
  }

  std::cout << ans << "\n";

  return 0;
}