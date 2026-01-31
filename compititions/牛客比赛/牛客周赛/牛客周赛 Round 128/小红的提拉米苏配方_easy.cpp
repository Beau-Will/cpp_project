#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  std::vector<std::array<int,2>> pos;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      if(i+1 == s.size()){
        pos.push_back({2,i});
      }else{
        pos.push_back({s[i+1]-'0',i});
      }
    }
  }

  std::sort(pos.begin(),pos.end());

  std::vector<int> vis(s.size());

  int end = pos.size()/2;
  for(int i = 0; i < end; i++){
    auto [v1,idx1] = pos[i];
    auto [v2,idx2] = pos[pos.size()-1-i];

    vis[idx1] = 2;
    vis[idx2] = 1;
  }

  std::string ans;
  for(int i = 0; i < s.size(); i++){
    if(vis[i] == 0){
      ans += s[i];
    }else if(vis[i] == 1){
      ans += '2';
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