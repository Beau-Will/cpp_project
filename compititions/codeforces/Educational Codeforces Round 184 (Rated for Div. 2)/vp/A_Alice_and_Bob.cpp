#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,a;
  std::cin >> n >> a;

  std::vector<int> v(n);
  for(int i = 0; i < n; i++){
    std::cin >> v[i];
  }

  int cnt1 = 0,cnt2 = 0;
  for(int i = 0; i < n; i++){
    if(v[i] <= a){
      cnt1++;
    }
    if(v[i] >= a){
      cnt2++;
    }
  }

  if(cnt1 > cnt2){
    std::cout << a-1 << "\n";
  }else{
    std::cout << a+1 << "\n";
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

  return 0;
}