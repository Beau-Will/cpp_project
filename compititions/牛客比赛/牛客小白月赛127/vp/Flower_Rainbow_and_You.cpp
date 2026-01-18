#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::vector<std::string> s = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
  std::vector<int> cnt(s.size());

  for(int i = 0; i < s.size(); i++){
    std::cin >> cnt[i];
  }

  std::cout << s[std::max_element(cnt.begin(),cnt.end())-cnt.begin()] << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}