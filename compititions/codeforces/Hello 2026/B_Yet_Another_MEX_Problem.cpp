#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<int> cnt(n+1);
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
  }

  int rest = n-k+1;
  for(int i = 0; i <= n; i++){
    if(cnt[i] == 0){
      break;
    }
    int min = std::min(rest,cnt[i]-1);
    rest -= min;
    cnt[i] -= min;
    if(rest == 0){
      break;
    }
  }

  if(rest){
    for(int i = n; i >= 0; i--){
      if(cnt[i]){
        int min = std::min(rest,cnt[i]);
        cnt[i] -= min;
        rest -= min;
      }
      if(rest == 0){
        break;
      }
    }
  }

  for(int i = 0; i <= n; i++){
    if(cnt[i] == 0){
      std::cout << i << "\n";
      return;
    }
  }

  std::cout << n+1 << "\n";
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