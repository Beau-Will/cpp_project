#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> a(n*2+1),b(n*2+1),c(n*2+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
    a[i+n] = a[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> b[i];
    b[i+n] = b[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> c[i];
    c[i+n] = c[i];
  }

  i64 cnt1 = 0,cnt2 = 0;
  for(int i = 0; i < n; i++){
    bool isok = true;
    for(int j = 1; j <= n; j++){
      if(a[i+j] >= b[j]){
        isok = false;
        break;
      }
    }
    if(isok){
      cnt1++;
    }
  }

  for(int i = 0; i < n; i++){
    bool isok = true;
    for(int j = 1; j <= n; j++){
      if(b[i+j] >= c[j]){
        isok = false;
        break;
      }
    }
    if(isok){
      cnt2++;
    }
  }

  std::cout << n*cnt1*cnt2 << "\n";
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