#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m, k;
  std::cin >> n >> m >> k;

  i64 min = 1LL * n * (n - 1) / 2;
  if(k < min){
    std::cout << "NO\n";
    return;
  }
  
  int d = k - min;
  std::vector<int> x(n + 1);
  i64 next = (1LL << 62);
  for(int i = n - 1; i >= 1; i--){
    i64 s = 1LL * (i - 1) * (i - 2) / 2;
    int v = m - n + 1;
    int cap = std::min(s, 1LL * v);
    int val = std::min<i64>({cap, next, d});
    x[i] = val;
    d -= val;
    next = val;
  }

  if(d > 0){
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
  std::vector<bool> vis(m + 1);
  std::vector<int> r;
  for(int i = 1; i < n; i++){
    int w = i + x[i];
    vis[w] = 1;
    std::cout << i << " " << i + 1 << " " << w << "\n";
  }

  for(int w = 1; w <= m; w++){
    if(!vis[w]){
      r.push_back(w);
    }
  }

  int need = m - (n - 1), id = 0;
  for(int v = 3; v <= n && id < need; v++){
    for(int u = 1; u <= v - 2 && id < need; u++){
      std::cout << u << " " << v << " " << r[id++] << "\n";
    }
  }
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