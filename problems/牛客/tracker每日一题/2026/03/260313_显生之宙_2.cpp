#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin() + 1, a.end());

  i64 cur = 0, next = 0;

  for(int i = 1; i <= n - 1; i++){
    i64 val = a[i] + cur + next;
    if(val < 0){
      cur += val;
      next = 0;
    }else{
      next = val;
    }
  }

  std::cout << a.back() + cur + next << "\n";
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