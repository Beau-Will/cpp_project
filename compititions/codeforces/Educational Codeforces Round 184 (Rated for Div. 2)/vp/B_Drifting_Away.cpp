#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  std::string s;
  std::cin >> s;

  if(s.size() == 1){
    std::cout << "1\n";
    return;
  }

  if(s.find("**") != std::string::npos){
    std::cout << "-1\n";
    return;
  }

  if(s.find("><")!=std::string::npos || s.find(">*<")!=std::string::npos){
    std::cout << "-1\n";
    return;
  }

  if(s.find(">*")!=std::string::npos||s.find("*<")!=std::string::npos){
    std::cout << "-1\n";
    return;
  }

  int idx1 = s.size(),idx2 = -1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '>'){
      idx1 = i;
      break;
    }
  }
  for(int i = s.size()-1; i >= 0; i--){
    if(s[i] == '<'){
      idx2 = i;
      break;
    }
  }

  std::cout << std::max(idx1,int(s.size()-1-idx2)) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}