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
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::sort(all(a));

  i64 sum = 0;
  for(int i = 1; i <= m-1; ++i){
    sum += 1LL*a[i+1]*a[i+1]-1LL*a[i]*a[i];
  }

  i64 ans = std::min(inf2,sum);

  for(int i = m+1; i <= n; ++i){
    sum -= a[i-m+1]*a[i-m+1]-a[i-m]*a[i-m];
    sum += a[i]*a[i]-a[i-1]*a[i-1];

    ans = std::min(ans,sum);
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