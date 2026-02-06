#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::set<int> set;
  i64 ans = 0;

  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;

    if(i == 0){
      ans += x;
    }else{
      int min = inf1;
      auto it1 = set.lower_bound(x);
      auto it2 = set.upper_bound(x);
      if(it2 == set.begin()){
        min = std::min(min, std::abs(*it2 - x));
      }else{
        min = std::min(min, std::abs(*(--it2) - x));
      }
      if(it1 == set.end()){
        min = std::min(min, std::abs(x - *(--it1)));
      }else{
        min = std::min(min, std::abs(*it1 - x));
      }
      ans += min;
    }

    set.insert(x);
  }

  std::cout << ans << "\n";
}

int main() {
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