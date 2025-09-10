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
  std::cin >> n >> m;

  std::vector<int> a(n+1),b(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; ++i){
    std::cin >> b[i];
  }

  std::vector<std::pair<int,int>> c(n+1);
  for(int i = 1; i <= n; ++i){
    if(b[i]>=a[i]){
      c[i] = {b[i]-a[i],a[i]+m-b[i]};
    }else{
      c[i] = {b[i]+m-a[i],a[i]-b[i]};
    }
  }

  std::sort(all(c));

  int ans = inf1,x = 0;
  for(int i = n; i >= 1; --i){
    ans = std::min(ans,c[i].first+x);
    x = std::max(x,c[i].second);
  }
  
  ans = std::min(ans,x);
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