#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  i64 l;
  std::cin >> n >> m >> l;

  std::vector<i64> x(n), y(m);
  for(int i = 0; i < n; i++){
    std::cin >> x[i];
  }
  for(int i = 0; i < m; i++){
    std::cin >> y[i];
  }

  std::vector<i64> z(n);
  i64 sum = 0;
  for(int i = 0; i < n; i++){
    sum += x[i];
    z[i] = sum;
  }

  i64 cur = 0;

  auto it = std::upper_bound(z.begin(), z.end(), cur);
  if(it != z.end() && *it < cur + l){
    std::cout << "YES\n";
    return;
  }

  for(int i = 0; i < m; i++){
    cur += y[i];

    it = std::upper_bound(z.begin(), z.end(), cur);
    if(it != z.end() && *it < cur + l){
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
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}