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

  std::sort(a.begin(),a.end());

  std::vector<int> b(2*n);
  for(int i = 0; i < n; i++){
    b[i] = a[i];
    b[n+i] = 8+a[i];
  }

  int cur = 0;
  for(int i = 0; i < n-1; i++){
    cur += b[i+1]-b[i];
  }
  int ans = cur;
  for(int i = 0; i < n-1; i++){
    cur -= b[i+1]-b[i];
    cur += b[n+i]-b[n-1+i];
    ans = std::min(ans,cur);
  }

  std::cout << ans << "\n";
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