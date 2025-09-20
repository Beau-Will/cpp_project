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
  int n,l1,r1,l2,r2;
  std::cin >> n >> l1 >> r1 >> l2 >> r2;

  std::vector<int> a(n-2);
  for(int i = 0; i < n-2; ++i){
    std::cin >> a[i];
  }

  if(n==3){
    for(int i = l1; i <= std::min(l1+9,r1); ++i){
      for(int j = l2; j <= std::min(l2+9,r2); ++j){
        if(1LL*i*j%10==a[0]){
          std::cout << i << " " << j << "\n";
          return;
        }
      }
    }
    std::cout << "-1 -1\n";
    return;
  }

  for(int i = l1; i <= std::min(l1+9,r1); ++i){
    for(int j = l2; j <= std::min(l2+9,r2); ++j){
      if(1LL*i*j%10==a[0]&&1LL*j*a[0]%10==a[1]){
        std::cout << i << " " << j << "\n";
        return;
      }
    }
  }

  std::cout << "-1 -1\n";
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