#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(),a.end());
  
  int rest = n;
  for(int i = n-1; i >= 0; i--){
    if(a[i] == 0){
      break;
    }
    int t = std::min(rest,a[i]-1);
    rest -= t;
    a[i] -= t;
    if(rest == 0){
      break;
    }
  }

  int cnt = 0;
  
  for(int i = 0; i < n; i++){
    if(a[i]){
      cnt++;
    }
  }

  if(cnt < rest){
    std::cout << "0\n";
    return;
  }

  if(rest == 0){
    std::cout << cnt << "\n";
    return;
  }

  std::cout << cnt-rest+1 << "\n";
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