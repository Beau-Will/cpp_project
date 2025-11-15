#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
  std::vector<int> pre(12);
  for(int i = 1; i < 12; i++){
    pre[i] = pre[i-1]+days[i-1];
  }
  int year,month,day;
  while(~scanf("%d/%d/%d",&year,&month,&day)){
    int ans = pre[month-1]+day;
    if((year%100==0)&&(year%400==0) || (year%100!=0)&&(year%4==0)){
      if(month>2){
        ans++;
      }
    }
    std::cout << ans << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}