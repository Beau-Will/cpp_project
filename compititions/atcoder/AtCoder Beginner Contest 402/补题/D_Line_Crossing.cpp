#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<std::pair<int,int>> a(m);
  for(int i = 0; i < m; ++i){
    std::cin >> a[i].first >> a[i].second;
  }

  std::vector<int> cnt(n);
  for(int i = 0; i < m; ++i){
    ++cnt[(a[i].first+a[i].second)%n];
  }
  
  i64 ans = 1LL*m*(m-1)/2;
  
  for(int i = 0; i < n; ++i){
    ans -= 1LL*cnt[i]*(cnt[i]-1)/2;
  }

  std::cout << ans << "\n";
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