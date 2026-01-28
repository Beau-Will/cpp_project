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

  std::vector<int> cnt(1E6+1);
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
  }

  std::vector<int> ans(1E6+1);
  for(int i = 1; i <= 1E6; i++){
    for(int j = i; j <= 1E6; j += i){
      ans[j] += cnt[i];
    }
  }

  for(int i = 0; i < n; i++){
    std::cout << ans[a[i]]-1 << "\n";
  }
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