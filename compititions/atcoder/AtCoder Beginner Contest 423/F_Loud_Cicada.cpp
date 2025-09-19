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
  int n,m;
  i64 Y;
  std::cin >> n >> m >> Y;

  std::vector<i64> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  std::vector<i64> f((1<<n)+1);

  f[0] = Y;

  auto gcd = [&](auto &&self,i64 x,i64 y)->i64{
    return !y ? x: self(self,y,x%y);
  };

  for(int S = 1; S < (1<<n); ++S){
    i64 l = 1;
    for(int i = 0; i < n; ++i){
      if((S>>i)&1){
        i64 g = gcd(gcd,l,a[i]);

        if(i128(l)/g*a[i]>i128(Y)){
          l = Y+1;
        }else{
          l = l/g*a[i];
        }
      }
    }
    f[S] = Y/l;
  }

  auto g = f;

  for(int i = 0; i < n; ++i){
    for(int S = 0; S < (1<<n); ++S){
      if(!((S>>i)&1)){
        g[S] -= g[S^(1<<i)];
      }
    }
  }

  i64 ans = 0;

  for(int S = 0; S < (1<<n); ++S){
    if(__builtin_popcount(S) == m){
      ans += g[S];
    }
  }

  std::cout << ans << "\n";
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