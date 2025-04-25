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
  int n,k;
  std::cin >> n >> k;

  if(n==1){
    std::cout << "0\n";
    return;
  }

  std::vector<int> a(n+1);
  a[n] = std::min(k,n-1);
  int cnt = 0;
  for(int i = 1; i <= n-1; ++i){
    if(cnt==k){
      ++cnt;
    }
    a[i] = cnt++;
  }

  for(int i = 1; i <= n; ++i){
    std::cout << a[i] << " \n"[i==n];
  }
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