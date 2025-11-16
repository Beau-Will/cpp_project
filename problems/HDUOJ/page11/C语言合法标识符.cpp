#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  auto is_num = [&](char c){
    return c>='0'&&c<='9';
  };
  auto is_letter = [&](char c){
    return c>='A'&&c<='Z' || c>='a'&&c<='z';
  };

  int n;
  while(std::cin >> n){
    std::string s;
    std::getline(std::cin, s);
    for(int i = 0; i < n; i++){
      std::getline(std::cin,s);
      if(s.front()=='_' || is_letter(s.front())){
        bool isok = true;
        for(int j = 1; j < s.size(); j++){
          if(!is_num(s[j]) && !is_letter(s[j]) && s[j]!='_'){
            isok = false;
            break;
          }
        }
        std::cout << (isok?"yes\n":"no\n");
      }else{
        std::cout << "no\n";
      }
    }
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