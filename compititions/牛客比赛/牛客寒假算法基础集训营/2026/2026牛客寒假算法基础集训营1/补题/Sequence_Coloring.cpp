#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  int cnt = 0;
  std::vector<int> next(n + 1);

  for(int i = 1; i <= n; i++){
    next[i] = std::max(next[i - 1], a[i] + i);
    if(a[i]){
      cnt++;
    }
  }

  if(cnt <= k){
    std::cout << "0\n";
    return;
  }

  auto check = [&](int t){
    int idx = 1;
    while(idx <= n && a[idx] == 0){
      idx++;
    }
    int res = 1, time = 0;
    while(idx <= n){
      time++;
      idx = next[idx];
      if(idx > n){
        break;
      }
      if(idx == next[idx]){
        while(idx <= n && idx == next[idx]){
          idx++;
        }
        if(idx <= n){
          time = 0;
          res++;
        }
      }else{
        if(time == t){
          idx++;
          while(idx <= n && a[idx] == 0){
            idx++;
          }
          if(idx <= n){
            time = 0;
            res++;
          }
        }
      }
    }
    return res <= k;
  };

  int lo = 1, hi = inf1;
  while(lo < hi){
    int mid = (lo + hi) >> 1;
    if(check(mid)){
      hi = mid;
    }else{
      lo = mid + 1;
    }
  }

  if(lo == inf1){
    std::cout << "-1\n";
    return;
  }

  std::cout << lo << "\n";
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