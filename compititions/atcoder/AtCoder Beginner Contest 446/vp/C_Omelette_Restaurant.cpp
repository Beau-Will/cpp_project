#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> b[i];
  }

  std::vector<int> t(n + 1);
  int last = 1;
  for(int i = 1; i <= n; i++){
    t[i] += a[i];
    int rest = b[i];

    for(int j = std::max(last, i - m); j <= i; j++){
      if(t[j] == 0){
        continue;
      }
      int tmp = std::min(t[j], rest);
      rest -= tmp;
      t[j] -= tmp;
      if(rest == 0){
        last = j;
        break;
      }
    }
  }

  int ans = 0;
  for(int i = std::max(1, n + 1 - m); i <= n; i++){
    ans += t[i];
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}