#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int n = s.size();
  s = " " + s;

  std::vector<int> pre(n + 1);
  for(int i = 2; i <= n; i++){
    pre[i] = pre[i - 1];
    if(s[i] == s[i - 1]){
      pre[i]++;
    }
  }

  i64 ans = 1;
  for(int r = 1; r < n; r++){
    if(s[r] == s[r + 1]){
      ans += (r - 1) - pre[r];
    }else{
      ans += pre[r];
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}