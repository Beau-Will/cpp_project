#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  i64 sum;
  std::cin >> n >> sum;

  if(sum < n){
    std::cout << "-1\n";
    return;
  }

  std::vector<i64> a = {0,1,4,8,48,88,488,888,4888,8888,48888,88888,488888,888888,4888888,8888888,48888888,88888888,488888888,888888888,4888888888LL,8888888888LL,48888888888LL,88888888888LL};

  int idx = 0;
  i64 tmp = 0;
  while(tmp<=sum){
    for(int i = 0; i < n; ++i){
      tmp += a[idx+1]-a[idx];
      if(tmp>sum){
        break;
      }
    }
    if(tmp>sum){
      break;
    }
    ++idx;
  }

  std::vector<i64> ans(n);
  i64 t = sum;
  for(int i = 0; i < n; ++i){
    ans[i] = a[idx];
    t -= a[idx];
  }
  for(int i = 0; i < n; ++i){
    if(t>=a[idx+1]-a[idx]){
      ans[i] += a[idx+1]-a[idx];
      t -= a[idx+1]-a[idx];
    }
  }

  for(int i = 0; i < n; ++i){
    std::cout << ans[i] << " \n"[i+1==n];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}