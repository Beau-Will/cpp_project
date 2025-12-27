#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,q;
  std::cin >> n >> q;

  std::vector<int> cnt(200001);
  std::vector<int> l(n),r(n);
  for(int i = 0; i < n; i++){
    std::cin >> l[i] >> r[i];

    cnt[l[i]-1]++;
    cnt[l[i]]++;
    cnt[l[i]+1]++;
    if(l[i]==r[i]){
      //
    }else if(l[i]+1==r[i]){
      cnt[r[i]+1]++;
    }else if(l[i]+2==r[i]){
      cnt[r[i]]++;
      cnt[r[i]+1]++;
    }else{
      cnt[r[i]-1]++;
      cnt[r[i]]++;
      cnt[r[i]+1]++;
    }
    // for(int i = 0; i <= 6; i++){
    //   std::cout << cnt[i] << " \n"[i==6];
    // }
  }
  // for(int i = 0; i <= 6; i++){
  //   std::cout << cnt[i] << " \n"[i==6];
  // }

  for(int qi = 0; qi<q; qi++){
    int x;
    std::cin >> x;
    std::cout << n-cnt[x] << " \n"[qi+1==q];
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