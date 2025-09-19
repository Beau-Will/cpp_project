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
  //  sigma(k-l+1)*(r-k+1)*ak
  //  =-sigma(k^2*ak)+(ri+li)sigma(k*ak)+(ri+1)(1-li)sigma(ak)

  int n,q;
  std::cin >> n >> q;

  std::vector<i64> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<i64> pre1(n+1),pre2(n+1),pre3(n+1);
  for(int i = 1; i <= n; ++i){
    pre1[i] = pre1[i-1]+1LL*i*i*a[i];
    pre2[i] = pre2[i-1]+1LL*i*a[i];
    pre3[i] = pre3[i-1]+a[i];
  }

  auto rangeQuery = [&](std::vector<i64> &pre,i64 l,i64 r){
    return pre[r]-pre[l-1];
  };

  for(int i = 0; i < q; ++i){
    i64 l,r;
    std::cin >> l >> r;

    std::cout << -rangeQuery(pre1, l, r)+(l+r)*rangeQuery(pre2, l, r)+(r+1)*(1-l)*rangeQuery(pre3, l, r) << "\n";
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