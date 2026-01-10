#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::pair<int,int>> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i].first;
    a[i].second = i+1;
  }

  std::sort(a.begin(),a.end());

  std::cout << a[0].second << " " << a[1].second << " " << a[2].second << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}