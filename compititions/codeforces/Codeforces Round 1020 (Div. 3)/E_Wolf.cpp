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

/*
7 4
3 1 5 2 7 6 4
3 4 2
2 3 5
1 5 6
1 7 3

3 1 5 2 7 6 4
1 2 3 4 5 6 7
*/
void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> where(n+1);
  for(int i = 1; i <= n; ++i){
    where[a[i]] = i;
  }

  std::vector<int> per(n+1);
  std::iota(all(per),0);

  for(;m--;){
    int l,r,x;
    std::cin >> l >> r >> x;

    int pos = where[x];
    if(pos>r||pos<l){
      std::cout << "-1" << " \n"[m==0];
      continue;
    }

    int lo = 1,hi = 1+r-l;
    int f = 1+pos-l;
    int cnt = 0;

    // std::vector<int> lower,upper;
    
    std::vector<int> c;
    while(lo != hi){
      int mid = (lo+hi)>>1;
      ++cnt;
      if(per[mid]==f){
        break;
      }else if(per[mid]>f){
        hi = mid-1;
        // upper.push_back(1);
        // ++upper;
        c.push_back(-1);
      }else{
        lo = mid+1;
        // ++lower;
        c.push_back(1);
      }
    }

    lo = l,hi = r;
    int lower = 0,upper = 0;
    int idx = 0,t = 0;
    while(lo != hi){
      int mid = (lo+hi)>>1;
      if(a[mid]==x){
        break;
      }else if(c[idx]==-1){
        hi = mid-1;
        if(a[mid]>x){
          ++upper;
          ++t;
        }else{
          ++lower;
        }
      }else{//c[idx]==1
        lo = mid+1;
        if(a[mid]>x){
          ++upper;
        }else{
          ++lower;
          ++t;
        }
      }
      ++idx;
    }

    if(x+upper<=n && x-lower>=1){
      int cnt0 = std::count(all(c),-1),cnt1 = std::count(all(c),1);
      int tmp = std::min(std::abs(upper-cnt0),std::abs(lower-cnt1));
      int ans = tmp+(c.size()-t-tmp);
      std::cout << ans << " \n"[m==0];
    }else{
      std::cout << "-1" << " \n"[m==0];
    }
  }
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