#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<std::vector<int>> d(200001);

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  int ans = 0,gcd = 0;
  std::vector<int> cnt(n+1);

  for(int i = 0; i < n; ++i){
    int _gcd = std::gcd(gcd,a[i]);

    for(auto div:d[a[i]]){
      ++cnt[div];
      if(div>_gcd){
        ans = std::max(ans,cnt[div]);
      }
    }

    if(gcd > _gcd){
      for(int j = _gcd+1; j <= n; ++j){
        ans = std::max(ans,cnt[j]);
      }
    }

    gcd = _gcd;

    std::cout << ans << " \n"[i+1==n];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for(int i = 1; i <= 200000; ++i){
    for(int j = i; j <= 200000; j+=i){
      d[j].push_back(i);
    }
  }

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}