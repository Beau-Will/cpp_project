#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> least(n),most(n);
  for(int i = 0; i < n; i++){
    std::cin >> least[i] >> most[i];
  }

  int leastSum = std::accumulate(least.begin(),least.end(),0);
  int mostSum = std::accumulate(most.begin(),most.end(),0);

  if(m < leastSum || m > mostSum){
    std::cout << "NO\n";
    return;
  }

  std::vector<int> ans(n);
  for(int i = 0; i < n; i++){
    ans[i] = least[i];
    m -= least[i];
  }

  for(int i = 0; i < n; i++){
    int t = std::min(m,most[i]-least[i]);
    ans[i] += t;
    m -= t;
  }

  std::cout << "YES\n";
  for(int i = 0; i < n; i++){
    std::cout << ans[i] << " \n"[i+1==n];
  }
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
}