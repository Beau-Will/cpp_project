#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::string s;
  std::getline(std::cin,s);

  std::unordered_map<char, int> cnt;
  for(const auto &c: s){
    cnt[c]++;
  }
  std::cout << "a:" << cnt['a'] << "\n";
  std::cout << "e:" << cnt['e'] << "\n";
  std::cout << "i:" << cnt['i'] << "\n";
  std::cout << "o:" << cnt['o'] << "\n";
  std::cout << "u:" << cnt['u'] << "\n\n";
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