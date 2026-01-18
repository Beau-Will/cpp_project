#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int firstOver5 = -1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] >= '5'){
      firstOver5 = i;
      break;
    }
  }

  // std::cout << firstOver5 << "\n";

  if(firstOver5 == -1){
    // s.back() = '0';         

    // std::cout << s << "\n";
    for(int i = 0; i < s.size()-1; i++){
      std::cout << s[i];
    }
    std::cout << "0\n";

    return;
  }

  int idx = firstOver5;

  // std::cout << idx << "\n";
  // std::cout << "???\n";

  if(idx == 0){
    std::cout << "10";
    for(int i = 1; i < s.size(); i++){
      std::cout << "0";
    }
    std::cout << "\n";

    return;
  }

  int firstNot9 = -1;
  for(int i = idx-1; i >= 0; i--){
    if(s[i] != '9'){
      firstNot9 = i;
      break;
    }
  }

  if(firstNot9 == -1){
    std::cout << "1";
    for(int i = 0; i < s.size(); i++){
      std::cout << "0";
    }
    // for(int i = idx+1; i < s.size(); i++){
    //   std::cout << s[i];
    // }
    std::cout << "\n";

    // for(int i = 0; i <= idx; i++){
    //   s[i] = '0';
    // }
    // std::reverse(s.begin(),s.end());
    // s += '1';
    // std::reverse(s.begin(),s.end());

    // std::cout << s << "\n";
    return;
  }

  for(int i = 0; i < firstNot9; i++){
    std::cout << s[i];
  }
  std::cout << char(s[firstNot9]+1);
  for(int i = firstNot9+1; i < s.size(); i++){
    std::cout << "0";
  }
  std::cout << "\n";

  // s[firstNot9] = s[firstNot9]+1;
  // for(int i = firstNot9+1; i <= idx; i++){
  //   s[i] = '0';
  // }

  // std::cout << s << "\n";
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
}