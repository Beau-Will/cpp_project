#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n;
  std::cin >> n;

  std::vector<i64> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  //等差数列
  //注意到需要满足条件：(首项+尾项)*项数/2>=a[i]
  //其中，首项为1，尾项=项数，不妨记尾项为x
  //即(1+x)*x/2>=a[i]
  //x单调 => 二分x

  auto work = [&](const i64 &ai){
    i64 lo = 1,hi = inf1;
    while(lo < hi){
      i64 mid = (lo+hi)>>1;
      if((1+mid)*mid/2>=ai){
        hi = mid;
      }else{
        lo = mid+1;
      }
    }
    return lo;
  };

  i64 ans = 0;
  for(int i = 0; i < n; ++i){
      ans += work(a[i]);
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}