#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::deque<int> a;
  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;
    a.push_back(x);
  }
  a.push_back(m);

  int cnt = 0;
  int ans = -1E9;
  while(cnt < 2 * n){
    auto front = a.front();
    auto back = a.back();
    ans = std::max(ans, front + back);
    a.pop_back();
    a.push_front(back);
    cnt++;
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