#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  std::map<char, int> cnt;
  for(int i = 0; i < s.size(); i++){
    cnt[s[i]]++;
  }

  int max = -1;
  for(const auto& [u, v] : cnt){
    max = std::max(max, v);
  }

  std::set<char> set;
  for(const auto& [u, v] : cnt){
    if(v == max){
      set.insert(u);
    }
  }

  for(const auto& c : s){
    if(set.count(c)){
      continue;
    }
    std::cout << c;
  }
  std::cout << "\n";
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