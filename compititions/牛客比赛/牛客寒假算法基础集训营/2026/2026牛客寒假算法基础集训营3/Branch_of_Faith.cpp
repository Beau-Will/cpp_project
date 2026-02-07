#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> cnt(1);

void solve(){
  int n, q;
  std::cin >> n >> q;

  for(int qi = 0; qi < q; qi++){
    i64 x;
    std::cin >> x;

    int idx = std::lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
    std::cout << std::min(n, cnt[idx]) - cnt[idx - 1] << "\n";
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  i64 t = 2;
  while(t <= 2E18){
    cnt.push_back(t - 1);
    t <<= 1;
  }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}