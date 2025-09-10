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
  int n,q;
  std::cin >> n >> q;

  std::string s;
  std::cin >> s;

  s = "?"+s;

  std::vector<int> a;
  for(int i = 1; i <= n; ++i){
    if(s[i]=='#'){
      a.push_back(i);
    }
  }

  for(int qi = 0; qi < q; ++qi){
    int x,y;
    std::cin >> x >> y;
    if(x>y){
      std::swap(x,y);
    }
    
    auto it1 = std::lower_bound(all(a),x);
    if(it1==a.end()){
      std::cout << "0\n";
      continue;
    }
    int idx1 = a[it1-a.begin()];
    
    auto it2 = std::upper_bound(all(a),y);
    if(it2==a.begin()){
      std::cout << "0\n";
      continue;
    }
    int idx2 = a[it2-a.begin()-1];

    std::cout << std::max(0,idx2-idx1+1) << "\n";
  }
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