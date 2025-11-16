#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  auto is_letter = [&](char c){
    return c>='A'&&c<='Z' || c>='a'&&c<='z';
  };

  std::string s;
  while(std::getline(std::cin,s)){
    bool flag = true;
    for(auto &c:s){
      if(is_letter(c) && flag){
        if(c>='a'&&c<='z'){
          c = 'A'+c-'a';
        }
        flag = false;
      }else if(c == ' '){
        flag = true;
      }
    }
    std::cout << s << "\n";
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