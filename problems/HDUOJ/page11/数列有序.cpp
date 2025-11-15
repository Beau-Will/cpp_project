#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m;
  while(std::cin >> n >> m){
    if(n==0 && m==0){
      break;
    }
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
      std::cin >> a[i];
    }

    
    a.push_back(m);
    std::sort(a.begin(),a.end());

    for(int i = 0; i < n+1; i++){
      std::cout << a[i] << " \n"[i==n];
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}