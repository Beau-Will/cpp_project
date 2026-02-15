#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, m;
  i64 h;
  std::cin >> n >> m >> h;

  std::vector<int> p(m + 1), f(m + 1);
  for(int i = 1; i <= m; i++){
    std::cin >> p[i] >> f[i];
  }

  std::vector<i64> a(n + 1), d(n + 2), dd(n + 2);

  auto update = [&](std::vector<i64>& diff, int l, int r, int c){
    diff[l] += c;
    diff[r + 1] -= c;
  };

  auto check = [&](int x){
    std::fill(a.begin(), a.end(), 0);
    std::fill(d.begin(), d.end(), 0);
    std::fill(dd.begin(), dd.end(), 0);

    for(int i = 1; i <= x; i++){
      //[p - f + 1,p]
      int idx1 = std::max(1, p[i] - f[i] + 1);
      if(idx1 == p[i] - f[i] + 1){
        update(dd, idx1, p[i], 1);
      }else{
        update(d, idx1, idx1, 1 - (p[i] - f[i] + 1));
        update(dd, idx1, p[i], 1);
      }

      //[p, p + f - 1]
      int idx2 = std::min(n, p[i] + f[i] - 1);
      update(dd, p[i] + 1, idx2 + 1, -1);
    }

    for(int i = 1; i <= n; i++){
      d[i] += d[i - 1] + dd[i];
    }
    for(int i = 1; i <= n; i++){
      a[i] += a[i - 1] + d[i];
    }

    for(int i = 1; i <= n; i++){
      if(a[i] > h){
        return true;
      }
    }

    return false;
  };

  int lo = 1, hi = m;
  bool isok = false;

  while(lo < hi){
    int mid = (lo + hi) >> 1;

    if(check(mid)){
      isok = true;
      hi = mid;
    }else{
      lo = mid + 1;
    }
  }

  if(check(lo)){
    isok = true;
  }

  std::cout << (isok ? "Yes\n" + std::to_string(lo) + "\n": "No\n");
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