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

  std::map<int,int> cnt;
  for(int i = 0; i < m; ++i){
    ++cnt[a[i].first+a[i].second];
  }

//  for(auto [u,v]:cnt){
//    std::cout << u << "," << v << "\n";
//  }

  i64 ans = 1LL*(m-1)*m/2;
  if(n&1){
    // std::cout << "---\n";
     for(auto [u1,v1]:cnt){
       if(v1>1){
         ans -= 1LL*(v1-1)*v1/2;
       }
       std::cout << u1 << "," << v1 << "\n"; 
       // std::cout << "***\n";
       int u2 = u1+n;
       int v2 = cnt[u2];
       ans -= 1LL*v1*v2;
     }
    // std::cout << "???\n";
  }else{
    for(auto [u,v]:cnt){
      if(v>1){
        ans -= 1LL*(v-1)*v/2;
      }
    }
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
