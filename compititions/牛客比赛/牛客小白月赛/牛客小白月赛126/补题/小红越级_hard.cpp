#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,q;
  std::cin >> n >> q;

  std::vector<i64> d(n+2),dd(n+2);
  
  auto update = [&](std::vector<i64> &diff,int left,int right,int c){
    diff[left] += c;
    diff[right+1] -= c;
  };

  for(int i = 0; i < n; i++){
    int l,r;
    std::cin >> l >> r;

    //[1,l-2]: 6 5 4 3 2 1
    //         1 2 ...   r-2
    if(1<=l-2){
      d[1] += (l-2)-1+1;
      update(dd,2,l-1,-1);
      // update(dd,1,1,(l-2)-1+1);
      // if(2<=l-2){
      //   update(dd,2,l-2,-1);
      // }
    }

    //[r+2,n]: 1 2 3 4 5 6 7
    //         r+2 ...     n
    if(r+2<=n){
      update(dd,r+2,n,1);
    }

    if(l+3<=r){
      int lp = (l+r)/2;
      int rp = lp+1;

      //[l+2,lp]: 1 2 3 4
      //          l+2   lp      
      update(dd,l+2,lp,1);
      d[lp+1] -= lp-(l+2)+1;

      //[rp,r-2]: 4 3 2 1
      //          rp    r-2
      d[rp] += (r-2)-rp+1;
      update(dd,rp+1,r-1,-1);
    }
  }

  for(int i = 1; i <= n; i++){
    dd[i] += dd[i-1];
    d[i] += dd[i];
  }

  for(int i = 1; i <= n; i++){
    d[i] += d[i-1];
  }

  for(int i = 0; i < q; i++){
    int x;
    std::cin >> x;

    std::cout << d[x] << " \n"[i+1==q];
  }
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