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

    std::vector<int> a(n),b(m);
    for(int i = 0; i < n; i++){
      std::cin >> a[i];
    }
    for(int i = 0; i < m; i++){
      std::cin >> b[i];
    }
    
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());

    std::vector<int> ans(n);

    auto it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
    ans.resize(it-ans.begin());

    if(ans.size()==0){
      std::cout << "NULL\n";
    }

    for(int i = 0; i < ans.size(); i++){
      std::cout << ans[i] << " \n"[i+1==ans.size()];
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