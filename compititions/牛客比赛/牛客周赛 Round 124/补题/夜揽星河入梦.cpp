#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+2);
  a[0] = -inf1;
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin()+1,a.begin()+n+1);

  std::vector<int> pre(n+1),suf(n+2);
  for(int i = 1; i <= n; i++){
    pre[i] = 1;
    if(a[i] == a[i-1]+1){
      pre[i] = std::max(pre[i],pre[i-1]+1);
    }
  }
  for(int i = n; i >= 1; i--){
    suf[i] = 1;
    if(a[i] == a[i+1]-1){
      suf[i] = std::max(suf[i],suf[i+1]+1);
    }
  }

  for(int i = 1; i <= n; i++){
    if(pre[i]>=m-1 || suf[i]>=m-1){
      std::cout << "YES\n";
      return;
    }
    if(a[i-1]+2==a[i] && pre[i-1]+suf[i]>=m-1){
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}