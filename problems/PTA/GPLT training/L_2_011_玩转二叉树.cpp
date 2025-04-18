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

  std::vector<int> in(n+1),pre(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> in[i];
  }
  for(int i = 1; i <= n; ++i){
    std::cin >> pre[i];
  }

  std::vector<int> ans(100001,-1);
  auto dfs = [&](auto &&self,int u,int l,int r,int idx)->void {
    if(l>r){
      return;
    }
    int i = l;
    while(i<r&&in[i]!=pre[u]){
      ++i;
    }
    ans[idx] = pre[u];
    self(self,u+1,l,i-1,idx*2+1);
    self(self,u+(i-l+1),i+1,r,idx*2);
  };

  dfs(dfs,1,1,n,1);
  
  bool flag = false;
  for(int i = 1; i <= 100000; ++i){
    if(ans[i]!=-1){
      if(!flag){
        std::cout << ans[i];
        flag = true;
      }else{
        std::cout << " " << ans[i];
      }
    }
  }
  std::cout << "\n";
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