#include <iostream>
#include <vector>

using i64 = long long;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<i64> w, v;
  for(int i = 0; i < n; i++){
    int wi, vi, si;
    std::cin >> wi >> vi >> si;

    int t = 1;
    while(t < si){
      w.push_back(1LL * wi * t);
      v.push_back(1LL * vi * t);
      si -= t;
      t <<= 1;
    }
    if(si){
      w.push_back(1LL * wi * si);
      v.push_back(1LL * vi * si);
      si = 0;
    }
  }

  std::vector<i64> dp(m + 1);
  for(int i = 0; i < w.size(); i++){
    for(int j = m; j >= w[i]; j--){
      dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
    }
  }

  std::cout << dp[m] << "\n";
}

int main() {
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