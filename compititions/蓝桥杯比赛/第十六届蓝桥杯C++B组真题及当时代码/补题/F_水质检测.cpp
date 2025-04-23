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
  int n = 2;
  
  std::vector<std::string> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
    a[i] = " "+a[i];
  }

  /*
  .     #     #
  # 是0 . 是1 #是2
  */

  int last_idx = -1,last_state = -1;
  int ans = 0;
  for(int i = 1; i < a[1].size(); ++i){
    if(a[1][i]=='.'&&a[2][i]=='.'){
      continue;
    }
    if(last_idx!=-1){
      ans += i-last_idx-1;
    }
    if(a[1][i]=='.'&&a[2][i]=='#'){
      if(last_state==1){
        ++ans;
        last_state = 2;
      }else{
        last_state = 0;
      }
    }else if(a[1][i]=='#'&&a[2][i]=='.'){
      if(last_state==0){
        ++ans;
        last_state = 2;
      }else{
        last_state = 1;
      }
    }else{
      last_state = 2;
    }
    last_idx = i;
  }

  std::cout << ans << "\n";
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