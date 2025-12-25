#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> w(n),p(n),s(n);
  i64 sump = 0;
  for(int i = 0; i < n; i++){
    std::cin >> w[i] >> p[i];
    s[i] = w[i]+p[i];
    sump += p[i];
  }

  std::sort(s.begin(),s.end());

  int ans = 0;
  for(int i = 0; i < n-1; i++){
    if(sump>=s[i]){
      sump -= s[i];
      ans++;
    }else{
      break;
    }
  }

  std::cout << ans << "\n";
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