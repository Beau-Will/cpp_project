#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, l, r;
  std::cin >> n >> l >> r;

  std::string s;
  std::cin >> s;

  std::map<char, std::vector<int>> map;
  for(int i = 0; i < s.size(); i++){
    map[s[i]].push_back(i);
  }

  i64 ans = 0;
  for(const auto& [u, v] : map){
    if(v.size() == 0){
      continue;
    }
    for(int i = 0; i < v.size(); i++){
      auto it1 = std::lower_bound(v.begin() + i, v.end(), v[i] + l);
      auto it2 = std::upper_bound(v.begin() + i, v.end(), v[i] + r);
      if(it1 == v.end()){
        continue;
      }
      ans += it2 - it1;
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