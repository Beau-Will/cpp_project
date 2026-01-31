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
  i64 n;
  int k;
  std::cin >> n >> k;

  auto isok = [&](i64 x){
    i64 t = x,_x = 0;
    while(t){
      _x = _x*10+t%10;
      t/=10;
    }
    return x == _x;
  };

  auto work = [&](){
    i64 t = n,_n = 0;
    while(t){
      _n = _n*10+t%10;
      t/=10;
    }
    n = n+_n;
  };

  for(int i = 0; i < k; ++i){
    if(isok(n)){
      std::cout << n << " " << i << "\n";
      return;
    }
    work();
  }

  std::cout << n << " " << (isok(n)?k:-1) << "\n";
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