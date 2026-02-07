#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<i64> a(n), b(m);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    std::cin >> b[i];
  }

  std::sort(a.begin(), a.end(), std::greater());
  std::sort(b.begin(), b.end(), std::greater());

  std::vector<i64> prea(n), preb(m);
  std::partial_sum(a.begin(), a.end(), prea.begin());
  std::partial_sum(b.begin(), b.end(), preb.begin());

  i64 suma = prea[n - 1];
  i64 sumb = preb[m - 1];
  if(suma == sumb){
    std::cout << "1\n";
    return;
  }

  if(suma > sumb){
    for(int i = 0; i < n; i++){
      if(suma - prea[i] <= sumb){
        std::cout << i + 1 << "\n";
        return;
      }
    }
  }else{
    for(int i = 0; i < m; i++){
      if(sumb - preb[i] <= suma){
        std::cout << i + 1 << "\n";
        return;
      }
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