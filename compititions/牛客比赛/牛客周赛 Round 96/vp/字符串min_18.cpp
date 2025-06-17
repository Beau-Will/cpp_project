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

  s = "0"+s+"1";

  std::vector<int> c(n+2);
  for(int i = 1; i <= n; ++i){
    std::cin >> c[i];
  }
  
  std::vector<i64> suf(n+3);
  for(int i = n+1; i > 0; --i){
    suf[i] = suf[i+1];
    if(s[i]!=s[i-1]){
      suf[i] += c[i];
    }
  }

  int cnt = 0;
  i64 ans = inf3,pre = 0;
  for(int i = 1; i <= n+1; ++i){
    int u = (s[i]-'0')^cnt;
    i64 cur = suf[i+1];

    if(u==0){
      cur += c[i];
    }

    ans = std::min(ans,cur+pre);

    if(s[i]!=s[i-1]){
      cnt ^= 1;
      pre += c[i];
    }
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}