#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;
  s = "?"+s;

  int diff = 0,idx = -1;
  for(int i = 1; i <= n; ++i){
    if(s[i]!='z'){
      idx = i;
      diff = 'z'-s[i];
      break;
    }
  }

  if(idx==-1){
    std::cout << s.substr(1) << "\n";
    return;
  }

  int j = idx+1;
  for(; j <= n; ++j){
    if(s[j]>s[idx]){
      break;
    }
  }

  for(int i = idx; i < j; ++i){
    s[i] += diff;
  }

  std::cout << s.substr(1) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}