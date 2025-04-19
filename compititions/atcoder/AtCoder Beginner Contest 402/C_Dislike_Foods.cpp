#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n,m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(m+1,std::vector<int>());
  for(int i = 1; i <= m; ++i){
    int k;
    std::cin >> k;
    a[i].resize(k);
    for(int j = 0; j < k; ++j){
      std::cin >> a[i][j];
    }
    // std::sort(a[i].begin(),a[i].end());
  }

  std::vector<int> b(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> b[i];
  }

  std::vector<int> map(n+1);
  for(int i = 1; i <= n; ++i){
    map[b[i]] = i;
  }

  std::vector<int> isok(n+1);
  for(int i = 1; i <= m; ++i){
    int max = 0;
    for(int j = 0; j < a[i].size(); ++j){
      max = std::max(max,map[a[i][j]]);
    }
    ++isok[max];
  }

  int sum = 0;
  for(int i = 1; i <= n; ++i){
    sum += isok[i];
    std::cout << sum << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}