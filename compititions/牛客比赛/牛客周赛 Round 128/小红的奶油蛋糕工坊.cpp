#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pos(n+1);
  for(int i = 1; i <= n; i++){
    pos[a[i]] = i;
  }

  std::vector<int> ans(n+1);
  if(((n+1)/2) % 2 == 1){
    int cnt = (n+1)/2;
    int x = (cnt+1)/2;
    for(int i = 1; i <= cnt; i++){
      ans[pos[i]] = x;
    }
  }else{
    int cnt = (n+1)/2;
    int x = cnt/2;
    for(int i = 1; i <= cnt; i++){
      ans[pos[i]] = x;
    }
  }

  for(int i = 1; i <= n; i++){
    if(ans[i] == 0){
      ans[i] = a[i];
    }
  }

  for(int i = 1; i <= n; i++){
    std::cout << ans[i] << " \n"[i==n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}