#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> p(n);
  for(int i = 0; i < n; i++){
    std::cin >> p[i];
  }

  std::vector<int> diff(n-1);
  for(int i = 0; i < n-1; i++){
    diff[i] = std::abs(p[i+1]-p[i]);
  }

  int m = n-1;

  std::vector<i64> left(m,-1);
  std::vector<i64> stk;

  for(int i = 0; i < m; i++){
    while(stk.size() && diff[stk.back()]>=diff[i]){
      stk.pop_back();
    }

    left[i] = stk.size()?stk.back():-1;
    stk.push_back(i);
  }

  stk.clear();

  std::vector<i64> right(m, m);

  for(int i = m-1; i >= 0; i--){
    while(stk.size() && diff[stk.back()]>diff[i]){
      stk.pop_back();
    }

    right[i] = stk.size()?stk.back():m;
    stk.push_back(i);
  }

  std::vector<i64> d(n+2,0);

  for(int i = 0; i < m; i++){
    i64 t = diff[i];
    i64 cnt = (i-left[i])*(right[i]-i);

    d[1] += cnt;
    if(t+1 <= n){
      d[t+1] -= cnt;
    }
  }
    
  std::vector<i64> ans(n);
  i64 cur = 0;
  for(int i = 1; i <= n-1; i++){
    cur += d[i];
    ans[i] = cur;
  }
  
  for(int i = 1; i <= n-1; i++){
    std::cout << ans[i] << " \n"[i==n-1];
  }
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