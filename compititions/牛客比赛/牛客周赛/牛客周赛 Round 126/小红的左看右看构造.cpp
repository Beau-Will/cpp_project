#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int x,y,n;
  std::cin >> x >> y >> n;

  std::vector<int> c(x),d(y);
  for(int i = 0; i < x; i++){
    std::cin >> c[i];
  }
  for(int i = 0; i < y; i++){
    std::cin >> d[i];
  }

  if(x+y-1 > n){
    std::cout << "-1\n";
    return;
  }
  if(c.back() != d.back()){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> ans(n);
  for(int i = 0; i < x; i++){
    ans[i] = c[i];
  }

  std::reverse(d.begin(),d.end());
  int last = -1;
  for(int i = x-1,j = 0; j < y; i++,j++){
    ans[i] = d[j];
    last = i;
  }
  for(int i = last+1; i < n; i++){
    ans[i] = d.back();
  }

  for(int i = 0; i < n; i++){
    std::cout << ans[i] << " \n"[i+1==n];
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}