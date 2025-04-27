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

  std::vector<int> a(n+1),b(m+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  for(int i = 1; i <= m; ++i){
    std::cin >> b[i];
  }

  std::vector<int> c(m+2);
  int j = m;
  for(int i = n; i >= 1; --i){
    if(a[i]>=b[j]){
      c[j] = i;
      --j;
      if(j<1){
        break;
      }
    }
  }
  c[m+1] = n+1;

  if(j<1){
    std::cout << 0 << "\n";
    return;
  }

  int ans = inf1*2;
  j = 1;
  for(int i = 1; i <= n; ++i){
    if(j<=m&&c[j+1]>=i){
      ans = std::min(ans,b[j]);
    }
    if(j<=m&&a[i]>=b[j]){
      ++j;
    }
    if(j<=m&&c[j+1]>i){
      ans = std::min(ans,b[j]);
    }
  }
  std::cout << (ans==inf1*2?-1:ans) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}