#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int m,n;
  std::cin >> m >> n;

  std::vector<int> a(n+1),b(n+1);
  std::vector<std::vector<int>> map(n+1);

  for(int i = 1; i <= n; ++i){
    int fa;
    std::cin >> a[i] >> b[i] >> fa;

    if(fa==0){
      map[i].push_back(i);
    }else{
      map[fa].push_back(i);
    }
  }

  std::vector<std::vector<std::pair<int,int>>> c;
  for(int i = 1; i <= n; ++i){
    if(map[i].size()==0){
      continue;
    }

    std::vector<std::pair<int,int>> tmp;
    for(int j = 0; j < (1<<(map[i].size())); ++j){
      if(__builtin_popcount(j)==0){
        continue;
      }
      bool isok = true;
      for(int k = 0; k < map[i].size(); ++k){
        if(map[i][k]==i){
          if(j>>k&1){
            break;
          }else{
            isok = false;
            break;
          }
        }
      }
      if(!isok){
        continue;
      }
      int sum1 = 0,sum2 = 0;
      for(int k = 0; k < map[i].size(); ++k){
        if(j>>k&1){
          sum1 += a[map[i][k]];
          sum2 += a[map[i][k]]*b[map[i][k]];
        }
      }
      tmp.push_back(std::make_pair(sum1, sum2));
    }

    c.push_back(tmp);
  }

  std::vector<int> dp(m+1);
  for(int i = 0; i < c.size(); ++i){
    for(int j = m; j >= 0; --j){
      for(int k = 0; k < c[i].size(); ++k){
        if(c[i][k].fi>j){
          continue;
        }
        dp[j] = std::max(dp[j],dp[j-c[i][k].fi]+c[i][k].se);
      }
    }
  }

  std::cout << dp[m] << "\n";
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