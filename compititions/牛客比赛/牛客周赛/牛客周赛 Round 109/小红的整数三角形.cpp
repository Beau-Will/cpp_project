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
  int x1,y1,x2,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  if(x1==x2){
    std::cout << x1+2 << " " << y1 << "\n";
  }else if(y1==y2){
    std::cout << x1 << " " << y1+2 << "\n";
  }else if(x2>x1){
    std::cout << x2+x2-x1 << " " << y1 << "\n";
  }else{
    std::cout << x1+x1-x2 << " " << y2 << "\n";
  }
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