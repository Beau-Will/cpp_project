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
  int n,a,k;
  std::cin >> n >> a >> k;

  if(n==1){
    if(a==k){
      std::cout << a << "\n";
    }else{
      std::cout << "-1\n";
    }
    return;
  }

  int cnt = (n+1)/2;
  a -= n;
  k -= cnt;

  int min = (a+1)/2;
  int max = a;

  if(k<min || k>max){
    std::cout << "-1\n";
    return;
  }

  std::cout << k+1 << " " << a-k+1;
  for(int i = 0; i < n-2; ++i){
    std::cout << " 1";
  }
  std::cout << "\n";
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