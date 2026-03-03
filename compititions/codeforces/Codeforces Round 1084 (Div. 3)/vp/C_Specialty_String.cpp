#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<char> stk;
  for(int i = 0; i < n; i++){
    if(stk.size()){
      auto t = stk.back();
      if(t == s[i]){
        stk.pop_back();
      }else{
        stk.push_back(s[i]);
      }
    }else{
      stk.push_back(s[i]);
    }
  }

  std::cout << (stk.size() ? "NO\n" : "YES\n");
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