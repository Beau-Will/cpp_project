#include <iostream>
#include <vector>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> A(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> A[i];
  }

  i64 ans = 0;
  int lastOddIdx = -1;

  for(int i = 1; i <= n; i++){
    if(A[i] & 1){
      lastOddIdx = i;
      ans += i;
    }else if(~lastOddIdx){
      ans += lastOddIdx;
    }
  }

  std::cout << ans << "\n";
}