#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(),a.end(),std::greater());

  std::vector<int> b(n);

  int ans = n;

  auto dfs = [&](auto &&self,int u,int cnt)->void {
    if(cnt >= ans){
      return;
    }

    if(u == n){
      ans = cnt;
      return;
    }

    for(int i = 0; i < cnt; i++){
      if(b[i]+a[u] <= m){
        b[i] += a[u];
        self(self,u+1,cnt);
        b[i] -= a[u];
      }
    }

    b[cnt] = a[u];
    self(self,u+1,cnt+1);
    b[cnt] = 0;
  };

  dfs(dfs,0,1);

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}