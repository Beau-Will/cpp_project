#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int l = 0,r = n-1;
  int cur1 = 0,cur2 = 0;
  while(l <= r){
    if(cur1 <= cur2){
        cur1 += a[l];
        l++;
    }else{
        cur2 += a[r];
        r--;
    }
  }

  std::cout << l << " " << n-1-r << "\n";
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