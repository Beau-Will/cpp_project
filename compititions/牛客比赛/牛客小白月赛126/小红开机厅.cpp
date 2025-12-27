#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;
  i64 x1,y1,x2,y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  i64 dx = std::abs(x1-x2);
  i64 dy = std::abs(y1-y2);

  i64 m = dx+dy;

  std::vector<i64> x(n),y(n);
  std::unordered_map<i64,int> cnt;

  cnt[m]+=2;

  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i];
    i64 dis1 = std::abs(x1-x[i])+std::abs(y1-y[i]);
    i64 dis2 = std::abs(x2-x[i])+std::abs(y2-y[i]);
    cnt[dis1+dis2]++;
  }

  for(int i = 0; i < n; i++){
    i64 dis1 = std::abs(x1-x[i])+std::abs(y1-y[i]);
    i64 dis2 = std::abs(x2-x[i])+std::abs(y2-y[i]);
    i64 c = dis1+dis2;

    if(c<m || c%2!=m%2){
      std::cout << 0 << " \n"[i+1==n];
      continue;
    }

    i64 A = dx+1,B = dy+1;

    i64 ans = 0;
    i64 k = (c-m)/2;
    if(k==0){
      // A*B
      ans = A*B;
    }else{
      //2(A+B)+4(K−1)
      ans = 2*(A+B)+4*(k-1);
    }
    ans -= cnt[c];
    std::cout << ans << " \n"[i+1==n];
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