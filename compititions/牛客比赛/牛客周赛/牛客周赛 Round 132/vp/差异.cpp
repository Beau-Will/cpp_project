#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::string> s(n);
  for(int i = 0; i < n; i++){
    std::cin >> s[i];
  }

  std::vector<int> cnt1(m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(s[i][j] == '1'){
        cnt1[j]++;
      }
    }
  }

  for(int i = 0; i < n; i++){
    int res = 0;
    for(int j = 0; j < m; j++){
      if(s[i][j] == '1'){
        res += n - cnt1[j];
      }else{
        res += cnt1[j];
      }
    }

    int cur = 0, min = 0;
    for(int j = 0; j < m; j++){
      int d;
      if(s[i][j] == '1'){
        d = cnt1[j] - 1 - (n - cnt1[j]);
      }else{
        d = (n - cnt1[j] - 1) - cnt1[j];
      }
      cur = std::min(0, cur + d);
      if(cur < min){
        min = cur;
      }
    }

    int ans = std::min(res, res + min);

    std::cout << ans << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}