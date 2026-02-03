#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using i64 = long long;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
  i64 avg = sum / n, ans = 0;

  if(sum % n == 0){
    for(int i = 0; i < n; i++){
      if(a[i] > avg){
        ans += a[i] - avg;
      }
    }
    std::cout << ans << "\n";
    return 0;
  }

  auto get = [&](int p, int idx){
    i64 res = 0;
    for(int i = 0; i < n; i++){
      if(i == idx){
        continue;
      }
      if(a[i] > p){
        res += a[i] - p;
      }
    }
    return res;
  };

  int minidx = std::min_element(a.begin(), a.end()) - a.begin();
  int maxidx = std::max_element(a.begin(), a.end()) - a.begin();

  i64 k = (sum - a[maxidx]) % (n - 1);
  ans = get((sum - a[maxidx]) / (n - 1), maxidx);
  ans = std::min(ans,get((sum - a[maxidx]) / (n - 1) + 1, maxidx) + n - 1 - k);
  k = (sum - a[minidx]) % (n - 1);
  ans = std::min(ans, get((sum - a[minidx]) / (n - 1), minidx));
  ans = std::min(ans, get((sum - a[minidx]) / (n - 1) + 1, minidx) + n - 1 -k);

  std::cout << ans << "\n";

  return 0;
}