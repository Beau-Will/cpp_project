#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<std::array<int,2>> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i][0];
    a[i][1] = i;
  }

  std::sort(a.begin() + 1, a.end());

  std::vector<int> at(n + 1);
  for(int i = 1; i <= n; i++){
    at[a[i][1]] = i;
  }

  std::vector<i64> suf(n + 2);
  for(int i = n; i >= 1; i--){
    suf[i] = suf[i + 1] + a[i][0];
  }

  std::vector<i64> ans(n + 1), diff(n + 2);
  std::vector<int> tag(n + 1), difftag(n + 2);

  auto update = [&](auto& d, int l, int r, int c){
    d[l] += c;
    d[r + 1] -= c;
  };

  for(int i = 1; i <= n; i++){
    int j = std::upper_bound(a.begin() + i + 1, a.end(), std::array{m - a[i][0], n})
    - a.begin();
    //[i + 1, j - 1]
    if(i + 1 <= j - 1){
      tag[i] += (j - 1) - (i + 1) + 1;
      update(difftag, i + 1, j - 1, 1);
    }
    //[j, n]
    if(j <= n){
      ans[i] -= suf[j];
      update(diff, j, n, -a[i][0]);
    }
  }

  for(int i = 1; i <= n; i++){
    diff[i] += diff[i - 1];
    difftag[i] += difftag[i - 1];

    ans[i] += static_cast<i64>(tag[i] + difftag[i]) * a[i][0];
    ans[i] += diff[i];
  }

  for(int i = 1; i <= n; i++){
    std::cout << ans[at[i]] << " \n"[i == n];
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