#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  while(std::cin >> n){
    std::string s;
    std::getline(std::cin,s);
    
    for(int i = 0; i < n; i++){
      std::getline(std::cin,s);
      auto t = s;
      std::reverse(t.begin(),t.end());
      
      bool isok = true;
      for(int j = 0; j < s.size(); j++){
        if(s[j]!=t[j]){
          isok = false;
          break;
        }
      }

      std::cout << (isok?"yes\n":"no\n");
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