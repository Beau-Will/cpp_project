#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,m;
  std::cin >> n >> m;

  std::vector<std::array<int,2>> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i][0];
    a[i][1] = i;
  }

  std::sort(a.begin() + 1,a.end());

  std::map<int,int> id;
  for(int i = 1; i <= n; i++){
    id[a[i][1]] = i;
  }

  std::vector<i64> suf(n+2);
  for(int i = n; i >= 1; i--){
    suf[i] = suf[i+1] + a[i][0];
  }

  std::vector<i64> ans(n+1), cnt(n+1);
  std::vector<i64> diff(n+5), diff_cnt(n+5);

  auto update = [&](std::vector<i64>& d,int l,int r,int c){
    d[l] += c;
    d[r + 1] -= c;
  };

  // for(int i = 1; i <= n; i++){
  //   std::cout << a[i][0] << " \n"[i==n];
  // }

  for(int i = 1; i <= n; i++){
    std::array<int,2> t = {m - a[i][0], n+1};
    int j = std::upper_bound(a.begin()+i+1,a.end(),t) - a.begin();
    // std::cout << j << " \n"[i == n];

    // std::cout << j << " \n"[i==n];
    //[1, j-1]
    if(j > i+1){
      cnt[i] += (j-1)-(i+1)+1;
      update(diff_cnt,i+1,j-1,1);
    }
    //[j, n]
    if(j <= n){
      ans[i] -= suf[j];
      update(diff,j,n,-a[i][0]);
    }
  }

  for(int i = 1; i <= n; i++){
    diff[i] += diff[i-1];
    diff_cnt[i] += diff_cnt[i-1];
  }

  for(int i = 1; i <= n; i++){
    ans[i] += cnt[i]*a[i][0];
    ans[i] += diff_cnt[i]*a[i][0];
    ans[i] += diff[i];
  }

  for(int i = 1; i <= n; i++){
    std::cout << ans[id[i]] << " \n"[i==n];
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