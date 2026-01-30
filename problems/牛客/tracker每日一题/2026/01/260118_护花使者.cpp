#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::pair<int,int>> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i].first >> a[i].second;
  }

  std::sort(a.begin()+1,a.end(),[&](const auto& p1,const auto& p2){
    return p1.first*p2.second < p1.second*p2.first;
  });

  std::vector<int> suf(n+2);
  for(int i = n; i >= 1; i--){
    suf[i] = suf[i+1]+a[i].second;
  }

  i64 ans = 0;

  for(int i = 1; i <= n; i++){
    ans += 1LL*a[i].first*2*suf[i+1];
  }

  std::cout << ans << "\n";
}