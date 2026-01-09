#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  //修改一次的贡献为(r-l+1)*(l+r)-(pre[r]-pre[l-1])
  //化简得f(r)-f(l-1),f(x)=x*x+x-pre[x]
  //答案为pre[n]+f(r)-f(l-1)
  std::vector<i64> a(n+1),pre(n+1),f(n+1);

  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
    pre[i] = pre[i-1]+a[i];
    f[i] = 1LL*i*i+i-pre[i];
  }

  //预处理计算前缀最小f函数值fmin
  std::vector<i64> minf(n+1);
  for(int i = 1; i <= n; i++){
    minf[i] = std::min(minf[i-1],f[i]);
  }

  //记max{f(r)-f(l-1)} = max
  //枚举r，由于l<=r,那么l-1<=r-1
  //min{f(l-1)}(1<=l<=r)即为minf[r-1]
  i64 max = 0;
  for(int r = 1; r <= n; r++){
    i64 minfl = minf[r-1];
    max = std::max(max,f[r]-minfl);
  }

  std::cout << pre[n]+max << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}