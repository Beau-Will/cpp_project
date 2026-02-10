#include <iostream>
#include <vector>
#include <numeric>

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pre(n + 1), suf(n + 2);
  for(int i = 1; i <= n; i++){
    pre[i] = pre[i - 1] ^ a[i];
  }
  for(int i = n; i >= 1; i--){
    suf[i] = suf[i + 1] ^ a[i];
  }

  int ans = pre[n];
  for(int i = 0; i <= n; i++){
    ans = std::max(ans, pre[i] & suf[i + 1]);
  }

  std::cout << ans << "\n";
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