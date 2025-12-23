#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<int> cnt(n+1);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
    if(cnt[a[i]+1]>=cnt[a[i]] && cnt[a[i]-1]>=cnt[a[i]]){
      ans--;
    }else if(cnt[a[i]+1]<cnt[a[i]] && cnt[a[i]-1]<cnt[a[i]]){
      ans++;
    }
    std::cout << ans << " \n"[i+1==n];
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