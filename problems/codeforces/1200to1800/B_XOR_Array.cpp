#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,l,r;
  std::cin >> n >> l >> r;

  std::vector<int> pre(n+1);

  std::iota(pre.begin(),pre.end(),0);
  pre[r] = l-1;

  for(int i = 1; i <= n; i++){
    std::cout << (pre[i]^pre[i-1]) << " \n"[i==n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}