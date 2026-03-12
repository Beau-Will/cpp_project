#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n + 1), diff(n + 3);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin() + 1, a.end());

  auto update = [&](int l, int r, i64 x){
    diff[l] += x;
    diff[r + 1] -= x;
  };

  for(int i = 1; i <= n - 1; i++){
    diff[i] += diff[i - 1];
    a[i] += diff[i];
    if(a[i] < 0){
      update(i + 1, n, a[i]);
    }else{
      update(i + 1, i + 1, a[i]);
    }
  }

  std::cout << a.back() << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}