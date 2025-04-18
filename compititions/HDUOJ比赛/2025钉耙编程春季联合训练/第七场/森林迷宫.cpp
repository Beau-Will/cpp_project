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

  std::vector<std::vector<std::pair<int,int>>> adj(n+1);
  for(int i = 0; i < n-1; ++i){
    int u,v,p,q;
    std::cin >> u >> v >> p >> q;
    adj[u].push_back({v,p});
    adj[v].push_back({u,q});
  }

  int s,t;
  std::cin >> s >> t;

  

}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}