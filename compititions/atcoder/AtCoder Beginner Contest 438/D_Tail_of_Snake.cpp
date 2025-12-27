#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n+1),b(n+1),c(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> b[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> c[i];
  }

  std::vector<i64> prea(n+1),preb(n+1),prec(n+1);
  for(int i = 1; i <= n; i++){
    prea[i] = prea[i-1]+a[i];
    preb[i] = preb[i-1]+b[i];
    prec[i] = prec[i-1]+c[i];
  }

  //ans = prea[x]+(preb[y]-preb[x])+(prec[n]-prec[y])
  //    = (prea[x]-preb[x])+(preb[y]-prec[y])+prec[n]
  //    = d1[x]+d2[y]+prec[n]
  //      1 <= x < y < n

  std::vector<i64> d1(n+1),d2(n+1);
  for(int i = 1; i <= n; i++){
    d1[i] = prea[i]-preb[i];
    d2[i] = preb[i]-prec[i];
  }

  std::vector<i64> maxD1(n+1);
  maxD1[0] = -1E18;
  for(int i = 1; i <= n; i++){
    maxD1[i] = std::max(maxD1[i-1],d1[i]);
  }

  i64 ans = -1E18;

  for(int y = n-1; y > 1; y--){
    ans = std::max(ans,maxD1[y-1]+d2[y]+prec[n]);
  }

  std::cout << ans << "\n";
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