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
  int n;
  std::cin >> n;

  int base = inf1;
  std::set<i64> set;

  std::vector<std::pair<int,int>> a(n);
  for(auto &[x,y]:a){
    std::cin >> x >> y;
    set.insert(1LL*x*base+y);
  }

  std::vector<int> dx = {1,2,2,1,-1,-2,-2,-1};
  std::vector<int> dy = {2,1,-1,-2,-2,-1,1,2};

  std::unordered_map<i64, int> map;

  for(auto &[x,y]:a){
    for(int i = 0; i < dx.size(); ++i){
      int u = x+dx[i],v = y+dy[i];
      if(u<1||v<1){
        continue;
      }
      i64 t = 1LL*u*base+v;
      ++map[t];
    }
  }

  i64 ans = -1;
  int max = 0;
  for(auto &[u,v]:map){
    if(set.contains(u)){
      continue;
    }
    if(v>max){
      max = v;
      ans = u;
    }
  }

  for(int x = 1; ans==-1; ++x){
    for(int y = 1; ans==-1; ++y){
      i64 t = 1LL*x*base+y;
      if(set.contains(t)){
        continue;
      }
      ans = t;
    }
  }

  std::cout << ans/base << " " << ans%base << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}