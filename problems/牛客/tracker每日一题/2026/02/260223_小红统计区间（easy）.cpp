#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  i64 k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  int l = 1, r = 0;
  i64 sum = 0, ans = 0;
  for(int i = 1; i <= n; i++){
    r++;
    sum += a[r];
    while(sum >= k){
      ans += n + 1 - r;
      sum -= a[l++];
    }
  }

  std::cout << ans << "\n";

  return 0;
}