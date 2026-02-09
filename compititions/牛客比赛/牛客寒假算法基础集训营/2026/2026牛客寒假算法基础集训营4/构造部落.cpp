#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, q, s;
  std::cin >> n >> q >> s;

  std::vector<int> t(n);
  for(int i = 0; i < n; i++){
    std::cin >> t[i];
  }

  std::vector<int> res = {s - 1};
  int cur = s - 1;
  for(int i = 0; i < n; i++){
    cur += t[i];
    res.push_back(cur);
  }

  for(int i = 0; i < q; i++){
    int x, y;
    std::cin >> x >> y;

    std::cout << res[x - 1] + y << "\n";
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