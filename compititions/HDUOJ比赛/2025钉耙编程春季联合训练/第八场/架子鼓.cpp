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
  int n1,n2;
  std::cin >> n1  >> n2;

  std::vector<std::pair<int,int>> a(n1);
  for(int i = 0; i < n1; ++i){
    std::cin >> a[i].fi >> a[i].se;
  }

  std::vector<std::pair<int,int>> b(n2);
  for(int i = 0; i < n2; ++i){
    std::cin >> b[i].fi >> b[i].se;
  }

  auto lcm = [&](int a,int b){
    return a/std::gcd(a,b)*b;
  };

  // std::set<std::pair<int,int>> set1,set2;
  std::vector<std::pair<int,int>> set1,set2;
  std::pair<int,int> cur1 = {0,0};
  for(int i = 0; i < n1; ++i){
    // set1.insert(cur1);
    if(cur1!=std::make_pair(0,0)){
      int gcd = std::gcd(cur1.fi,cur1.se);
      set1.push_back({cur1.fi/gcd,cur1.se/gcd});
    }else{
      set1.push_back(cur1);
    }
    // set1.push_back(cur1);
    // int t1 = 1,t2 = 1;
    if(cur1!=std::make_pair(0,0)){
      int cur_lcm = lcm(cur1.second,a[i].se);
      int t1 = cur_lcm/a[i].se;
      int t2 = cur_lcm/cur1.se;
      // std::pair<int,int> tmp = {a[i].fi*t1,a[i].se*t1};
      cur1.fi *= t2;
      cur1.fi += a[i].fi*t1;
      cur1.se = cur_lcm;
    }else{
      cur1.fi += a[i].fi;
      cur1.se = a[i].se;
    }
    // std::cout << cur1.fi << " " << cur1.se << "\n";
  }

  std::pair<int,int> cur2 = {0,0};
  for(int i = 0; i < n2; ++i){
    // set2.insert(cur2);
    if(cur2!=std::make_pair(0,0)){
      int gcd = std::gcd(cur2.fi,cur2.se);
      set2.push_back({cur2.fi/gcd,cur2.se/gcd});
    }else{
      set2.push_back(cur2);
    }
    // int t1 = 1,t2 = 1;
    if(cur2!=std::make_pair(0,0)){
      int cur_lcm = lcm(cur2.second,b[i].se);
      int t1 = cur_lcm/b[i].se;
      int t2 = cur_lcm/cur2.se;
      // std::pair<int,int> tmp = {b[i].fi*t1,b[i].se*t1};
      cur2.fi *= t2;
      cur2.fi += b[i].fi*t1;
      cur2.se = cur_lcm;
    }else{
      cur2.fi += b[i].fi;
      cur2.se = b[i].se;
    }
    // std::cout << cur2.fi << " " << cur2.se << "\n";
  }

  std::sort(all(set1));
  std::sort(all(set2));

  std::vector<std::pair<int,int>> ans;
  std::set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),std::insert_iterator<std::vector<std::pair<int,int>>>(ans,ans.begin()));
  std::cout << ans.size() << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}