#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s,t;
  std::cin >> s >> t;

  std::map<char,int> cnts,cntt;
  for(const auto& c:s){
    cnts[c]++;
  }
  for(const auto& c:t){
    cntt[c]++;
  }

  for(const auto& [u,v]:cnts){
    if(cntt[u] < v){
      std::cout << "Impossible\n";
      return;
    }
  }

  std::vector<char> t_;
  for(const auto& [u,v]:cntt){
    for(int i = 0; i < v-cnts[u]; i++){
      t_.push_back(u);
    }
  }

  std::string ans;
  int i = 0,j = 0;
  while(i < t_.size() && j < s.size()){
    if(t_[i] >= s[j]){
      ans += s[j];
      j++;
    }else{
      ans += t_[i];
      i++;
    }
  }
  while(i < t_.size()){
    ans += t_[i];
    i++;
  }
  while(j < s.size()){
    ans += s[j];
    j++;
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}