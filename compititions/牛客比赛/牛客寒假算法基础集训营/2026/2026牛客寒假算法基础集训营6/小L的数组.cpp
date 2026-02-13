#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr int max = 2048;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  std::vector<int> cur(max), next(max);
  cur[0] = 1;
  for(int i = 0; i < n; i++){
    std::fill(next.begin(), next.end(), 0);
    
    for(int j = 0; j < max; j++){
      if(!cur[j]){
        continue;
      }

      int t1 = std::max(0, j - a[i]);
      next[t1] = 1;
      int t2 = j ^ b[i];
      next[t2] = 1;
    }

    std::swap(cur, next);
  }

  int ans = 0;
  for(int i = max - 1; i >= 0; i--){
    if(cur[i]){
      ans = i;
      break;
    }
  }

  std::cout << ans << "\n";
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