#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::vector<std::string> a(n);
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  if(k&1){
    std::cout << "-1\n";
    return;
  }

  k>>=1;

  std::vector<std::string> ans(n,std::string(n,'0'));

  for(int i = 0; i < n; ++i){
    if(k){
      ans[i][i] = '1';
      --k;
    }
  }

  for(int i = 0; i < n; ++i){
    std::cout << ans[i] << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}