#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  i64 ans = 0;
  int maxDiff = 0;

  for(int i = 0; i < n-1; i++){
    int d = std::abs(a[i+1]-a[i]);
    maxDiff = std::max(maxDiff,std::abs(a[i+1]-a[i]));

    ans += std::max(0,(d+k-1)/k-1);
  }

  if(maxDiff < k){
    std::cout << "1\n";
    return 0;
  }

  std::cout << ans << "\n";
}