#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, p;
  std::cin >> n >> p;
  
  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pre(n + 1);
  for(int i = 1; i <= n; i++){
    pre[i] = (pre[i - 1] + a[i]) % p;
  }

  std::set<std::array<int, 2>> set;
  int ans = 0, l = 1, r = 1;

  set.insert({pre[0], 0});
  for(int i = 1; i <= n; i++){
    auto [pre1, idx1] = *set.begin();
    if(pre[i] - pre1 > ans){
      ans = pre[i] - pre1;
      l = idx1 + 1;
      r = i;
    }

    auto it = set.upper_bound({pre[i], n});
    if(it != set.end()){
      auto [pre2, idx2] = *it;
      if((pre[i] - pre2 + p) % p > ans){
        ans = (pre[i] - pre2 + p) % p;
        l = idx2 + 1;
        r = i;
      }
    }

    set.insert({pre[i], i});
  }

  std::cout << l - 1 << " " << r - 1 << " " << ans << "\n";
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