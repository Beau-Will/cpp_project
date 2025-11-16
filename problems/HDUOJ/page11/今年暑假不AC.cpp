#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  while(std::cin >> n){
    if(n==0){
      break;
    }

    std::vector<std::pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
      std::cin >> v[i].first >> v[i].second;
    }

    std::sort(v.begin(),v.end(),[&](auto &x,auto &y){
      if(x.second!=y.second){
        return x.second < y.second;
      }
      return x.first < y.first;
    });

    int ans = 0, now = 0;
    for(int i = 0; i < n; i++){
      if(now <= v[i].first){
        now = v[i].second;
        ans++;
      }
    }

    std::cout << ans << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}