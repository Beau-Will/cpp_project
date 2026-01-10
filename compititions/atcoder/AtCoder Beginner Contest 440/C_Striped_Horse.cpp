#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> sum(m*4);
  for(int i = 0; i < n; i++){
    sum[i%(m*2)] += a[i];
  }

  for(int i = 0; i < m*2; i++){
    sum[i+m*2] = sum[i];
  }

  std::vector<i64> pre(m*4);
  
  std::partial_sum(sum.begin(),sum.end(),pre.begin());

  i64 ans = inf2;
  for(int i = 0; i < m*2; i++){
    if(i == 0){
      ans = std::min(ans,pre[i+m-1]);
    }else{
      ans = std::min(ans,pre[i+m-1]-pre[i-1]);
    }
  }

  std::cout << ans << "\n";
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
}