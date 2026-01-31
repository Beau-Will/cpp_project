#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  int ans = 0;

  for(int i = 0; i < (n+1)/2; ++i){
    std::vector<int> v1 = {a[i]},v2 = {a[n-1-i]};
    int t1 = a[i],t2 = a[n-1-i];
    for(int j = 0; j < 31; ++j){
      t1 = t1^(t1>>1);
      t2 = t2^(t2>>1);
      v1.push_back(t1);
      v2.push_back(t2);
    }

    int min = inf1;
    for(int j = 0; j < v1.size(); ++j){
      for(int k = 0; k < v2.size(); ++k){
        if(v1[j]==v2[k]){
          min = std::min(min,j+k);
        }
      }
    }

    if(min == inf1){
      std::cout << "-1\n";
      return;
    }

    ans += min;
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}