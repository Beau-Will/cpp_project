#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, x;
  std::cin >> n >> x;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::unordered_map<int, int> cnt;
  for(int i = 0; i < n; i++){
    cnt[a[i]]++;
  }

  int max = 0;
  for(const auto& [u, v] : cnt){
    if(u == x){
      continue;
    }
    max = std::max(max, v);
  }

  std::cout << std::max(0, max - cnt[x]) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}