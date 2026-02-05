#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int max = *std::max_element(a.begin(), a.end());
  int cnt = std::count(a.begin(), a.end(), max);

  std::string ans(n, '0');
  if(cnt & 1){
    for(int i = 0; i < n; i++){
      if(a[i] == max){
        ans[i] = '1';
      }
    }
  }else{
    for(int i = 0; i < n; i++){
      if(a[i] ^ max){
        ans[i] = '1';
      }
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

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}