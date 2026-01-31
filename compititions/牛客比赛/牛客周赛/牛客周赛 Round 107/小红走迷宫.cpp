#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n,m,x;
  std::cin >> n >> m >> x;

  std::vector<int> a(n);
  for(int i = 0; i < x; ++i){
    int t;
    std::cin >> t;
    --t;
    a[t] = 1;
  }

  std::vector<std::vector<int>> adj(n);
  for(int i = 0; i < m; ++i){
    int u,v;
    std::cin >> u >> v;
    --u,--v;
    if(a[u]==0&&a[v]==0){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  std::vector<int> ans;

  auto bfs = [&](){
    std::queue<int> q;
    std::vector<bool> vis(n);
    q.push(0);
    vis[0] = true;

    while(!q.empty()){
      auto u = q.front();
      q.pop();
      ans.push_back(u);

      for(const auto &v:adj[u]){
        if(!vis[v]){
          vis[v] = true;
          q.push(v);
        }
      }
    }
  };

  bfs();

  std::sort(all(ans));

  for(int i = 0; i < ans.size(); ++i){
    std::cout << ans[i]+1 << " \n"[i+1==ans.size()];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}