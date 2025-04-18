#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> ans(n+1);
  int idx = 1;
  auto dfs = [&](auto &&self,int u) ->void {
    if(u>n){
      return;
    }
    self(self,u*2);
    self(self,u*2+1);
    ans[u] = a[idx++];
  };

  dfs(dfs,1);

  for(int i = 1; i <= n; ++i){
    std::cout << ans[i] << " \n"[i==n];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}