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

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> c(n);
  for(int i = 1; i <= n-1; ++i){
    c[i] = a[i]|a[i+1];
  }

  i64 ans = 0;

  //考虑b[1]
  int tmp = 1;
  for(int j = 0; j < m; ++j){
    int t1 = a[2]>>j&1;
    int t2 = c[1]>>j&1;
    if(t1==1&&t2==1){
      tmp *= 2;
    }
  }
  ans += tmp-1;
  // std::cout << "1 ans:" << ans << "\n";

  //考虑b[n]
  tmp = 1;
  for(int j = 0; j < m; ++j){
    int t1 = a[n-1]>>j&1;
    int t2 = c[n-1]>>j&1;
    if(t1==1&&t2==1){
      tmp *= 2;
    }
  }
  ans += tmp-1;
  // std::cout << "2 ans:" << ans << "\n";

  //考虑b[2]~b[n-1]
  for(int i = 2; i <= n-1; ++i){
    int cnt = 1;
    for(int j = 0; j < m; ++j){
      int t1 = c[i-1]>>j&1;
      int t2 = c[i]>>j&1;
      if(t1==1&&t2==1){
        int t3 = a[i-1]>>j&1;
        int t4 = a[i+1]>>j&1;
        if(t3==1 && t4==1){
          cnt *= 2;
        }
      }
    }
    ans += cnt-1;
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