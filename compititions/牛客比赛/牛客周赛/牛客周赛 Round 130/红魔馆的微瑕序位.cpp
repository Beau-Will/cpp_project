#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<int> pos(n + 1);
  for(int i = 1; i <= n; i++){
    pos[a[i]] = i;
  }

  std::vector<int> id(n + 1, -1);
  int t = 0;

  for(int i = 1; i <= n; i++){
    if(id[i] == -1){
      int cur = i;
      while(id[cur] == -1){
        id[cur] = t;
        cur = a[cur];
      }
      t++;
    }
  }

  i64 f = 0;
  for(int i = 1; i <= n; i++){
    f += std::abs(a[i] - i);
  }

  if(f == 2){
    std::cout << "0\n";
    return;
  }

  if(n == 2 && a[1] == 1){
    std::cout << "1\n";
    return;
  }

  int ans = n;
  for(int i = 1; i < n; i++){
    int x = pos[i];
    int y = pos[i + 1];

    if(id[x] == id[y]){
      ans = std::min(ans, n - 1 - t);
    }else{
      ans = std::min(ans, n + 1 - t);
    }
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