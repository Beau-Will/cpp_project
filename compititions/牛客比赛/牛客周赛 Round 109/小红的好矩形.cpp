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

  std::vector<std::pair<int,int>> a(n);
  std::set<std::pair<int,int>> set;
  for(auto &[x,y]:a){
    std::cin >> x >> y;
    set.insert({x,y});
  }

  i64 ans = 0;

  std::sort(all(a));
  std::map<int,int> mapy;
  
  for(auto &[x,y]:a){
    if(set.contains({x,y+1})){
      ans += mapy[y];
      ++mapy[y];
    }
  }

  std::sort(all(a),[&](auto &p1,auto &p2){
    if(p1.se!=p2.se) return p1.se < p2.se;
    return p1.fi < p2.fi;
  });
  std::map<int,int> mapx;
  
  for(auto &[x,y]:a){
    if(set.contains({x+1,y})){
      ans += mapx[x];
      ++mapx[x];
    }
  }

  for(auto &[x,y]:a){
    if(set.contains({x+1,y})&&set.contains({x,y+1})&&set.contains({x+1,y+1})){
      --ans;
    }
  }

  std::cout << ans << "\n";
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