#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n,m,k;
  std::cin >> n >> m >> k;

  std::vector<int> fa(n+1);
  auto is_enemy = std::vector(n+1,std::vector<bool>(n+1));

  std::iota(fa.begin(),fa.end(),0);

  auto find = [&](auto &&self,int u) ->int {
    if(u!=fa[u]){
      fa[u] = self(self,fa[u]);
    }
    return fa[u];
  };

  auto merge = [&](int u,int v){
    int u_fa = find(find,u);
    int v_fa = find(find,v);
    if(u_fa==v_fa){
      return false;
    }
    fa[v_fa] = u_fa;
    return true;
  };

  for(int i = 0; i < m; ++i){
    int u,v,op;
    std::cin >> u >> v >> op;
    if(op==1){
      merge(u,v);
    }else{
      is_enemy[u][v] = true;
      is_enemy[v][u] = true;
    }
  }

  for(int i = 0; i < k; ++i){
    int u,v;
    std::cin >> u >> v;
    int u_fa = find(find,u);
    int v_fa = find(find,v);
    if(u_fa==v_fa){
      if(is_enemy[u][v]){
        std::cout << "OK but...\n";
      }else{
        std::cout << "No problem\n";
      }
    }else{
      if(is_enemy[u][v]){
        std::cout << "No way\n";
      }else{
        std::cout << "OK\n";
      }
    }
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