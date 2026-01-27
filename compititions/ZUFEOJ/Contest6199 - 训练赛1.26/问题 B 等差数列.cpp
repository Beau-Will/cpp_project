#include <bits/stdc++.h>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(),a.end());
  a.erase(std::unique(a.begin(),a.end()),a.end());

  if(a.size() == 1){
    std::cout << "1\n";
    return;
  }

  int maxD = 0;
  for(int i = 0; i < a.size(); i++){
    maxD = std::__gcd(maxD,a[i]);
  }

  std::cout << (a.back()-a.front())/maxD+1 << "\n";
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