#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,q;
  std::cin >> n >> q;

  std::vector<int> diff(n+2),ans(n+2);

  auto update = [&](int left,int right,int c){
    diff[left] += c;
    diff[right+1] -= c;
  };

  for(int i = 0; i < n; i++){
    int l,r;
    std::cin >> l >> r;

    //[1,l-2]: +1
    if(1<=l-2){
      update(1,l-2,1);
    }

    //[r+2,n]: +1
    if(r+2<=n){
      update(r+2,n,1);
    }

    //[l+2,r-2]: +1
    if(l+2<=r-2){
      update(l+2,r-2,1);
    }
  }

  for(int i = 1; i <= n; i++){
    ans[i] = ans[i-1]+diff[i];
  }

  for(int i = 0; i < q; i++){
    int x;
    std::cin >> x;

    std::cout << ans[x] << " \n"[i+1==q];
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}