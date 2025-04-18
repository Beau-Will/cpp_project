#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  std::string s;
  getline(std::cin,s);

  // std::string line2 = line1;
  // std::reverse(line2.begin(),line2.end());

  int ans = 1;
  for(int len = 2; len <= s.size(); ++len){
    for(int i = 0; i <= s.size()-len; ++i){
      std::string t1 = s.substr(i,len);
      std::string t2 = t1;
      std::reverse(t2.begin(),t2.end());
      if(t1==t2){
        ans = len;
        break;
      }
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}