#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

auto is_upper = [](char c){
  return c>='A'&&c<='Z';
};
auto is_lower = [](char c){
  return c>='a'&&c<='z';
};
auto is_num = [](char c){
  return c>='0'&&c<='9';
};
auto is_special = [](char c){
  return c=='~'||c=='!'||c=='@'||c=='#'||c=='$'||c=='%'||c=='^';
};

void solve() {
  std::string s;
  std::getline(std::cin,s);

  if(s.size()<8||s.size()>16){
    std::cout << "NO\n";
    return;
  }

  int cnt = 0;
  for(auto &c: s){
    if(is_lower(c)){
      ++cnt;
      break;
    }
  }
  for(auto &c: s){
    if(is_upper(c)){
      ++cnt;
      break;
    }
  }
  for(auto &c: s){
    if(is_num(c)){
      ++cnt;
      break;
    }
  }
  for(auto &c: s){
    if(is_special(c)){
      ++cnt;
      break;
    }
  }

  std::cout << (cnt>=3?"YES\n":"NO\n");
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;

  std::string tmp;
  std::getline(std::cin,tmp);

  for (; T--;) {
    solve();
  }

  return 0;
}