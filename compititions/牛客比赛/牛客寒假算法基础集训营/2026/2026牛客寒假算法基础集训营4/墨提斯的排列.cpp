#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> p(1 << n);
  // 打表
  // std::iota(p.begin(), p.end(), 0);

  // int ans = inf1;
  // do{
  //   int cur = 0;
  //   for(int i = 1; i < (1 << n); i++){
  //     cur += p[i - 1] ^ p[i];
  //   }
  //   ans = std::min(ans, cur);
  // }while(std::next_permutation(p.begin(), p.end()));

  // std::cout << ans << "\n";

  // int res = 0;
  for(int i = 0; i < (1 << n); i++){
    p[i] = (i ^ (i >> 1));
  }
  // for(int i = 1; i < (1 << n); i++){
  //   res += (p[i - 1] ^ p[i]);
  // }
  // std::cout << res << "\n";

  for(int i = 0; i < (1 << n); i++){
    std::cout << p[i] << " \n"[i + 1 == (1 << n)];
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