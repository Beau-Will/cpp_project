#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<i64> tar;

void solve() {
  i64 x;
  std::cin >> x;

  int idx = std::lower_bound(tar.begin(),tar.end(),x)-tar.begin();

  i64 tar1 = tar[idx],tar2 = tar[idx+1];

  i64 tmp = x;
  i64 cnt1 = 0;
  if(tmp*9>tar1 && (tar1-tmp)%9!=0){
    cnt1 = 1E18;
  }else if(tmp*9>tar1){
    cnt1 = (tar1-tmp)/9;
  }else{
    i64 t1 = (tar1/9-tmp)/9;
    cnt1 += t1;
    tmp += t1*9;
    cnt1 ++;
    tmp *= 9;
    cnt1 += (tar1-tmp)/9;
    tmp += (tar1-tmp)/9*9;
  }

  i64 cnt2 = 0;
  tmp = x;
  i64 t2 = (tar2/9-tmp)/9;
  cnt2 += t2;
  tmp += t2*9;
  cnt2 ++;
  tmp *= 9;
  cnt2 += (tar2-tmp)/9;
  tmp += (tar2-tmp)/9*9;

  i64 ans = std::min(cnt1,cnt2);
  std::cout << ans << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  i64 tmp = 0;
  for(; tmp < 1E18; ){
    if(tmp!=0) tar.push_back(tmp);
    tmp = tmp*10+9;
  }

  std::sort(tar.begin(),tar.end());

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}