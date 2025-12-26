#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int l,r,p,q;
  std::cin >> l >> r >> p >> q;

  i64 ans = 0;

  int l_q = l%q,r_q = r%q;
  if(r_q-l_q == r-l){
    if(l_q>=p){
      ans += 0;
    }else if(l_q<p && r_q<p){
      ans += 1LL*(l_q+r_q)*(r_q-l_q+1)/2;
    }else{
      ans += 1LL*(l_q+(p-1))*((p-1)-l_q+1)/2;
    }
  }else{
    i64 tmp = 1LL*p*(p-1)/2;

    int tt1 = l+q-l_q;
    int tt2 = r-r_q;
    if(tt1!=tt2){
      ans += tmp*((tt2-tt1)/q);
    }

    //[l,tt1(l到r中第一个被q整除的数)]
    //[tt2(l到r中最后一个被q整除的数),r]
    if(l_q<p){
      ans += 1LL*(l_q+p-1)*(p-l_q)/2;
    }

    if(r_q<p){
      ans += 1LL*(1+r_q)*r_q/2;
    }else{
      ans += tmp;
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