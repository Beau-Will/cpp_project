#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m;
  std::cin >> n >> m;
  std::string s,t;
  std::cin >> s >> t;

  int ans = inf1;
  for(int i = 0; i+m-1 < n; i++){
    //[i,i+m-1]
    int cnt = 0;
    for(int j = 0; j < m; j++){
      if(s[i+j]<t[j]){
        cnt += s[i+j]+10-t[j];
      }else{
        cnt += s[i+j]-t[j];
      }
    }
    ans = std::min(ans,cnt);
  }

  std::cout << ans << "\n";
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