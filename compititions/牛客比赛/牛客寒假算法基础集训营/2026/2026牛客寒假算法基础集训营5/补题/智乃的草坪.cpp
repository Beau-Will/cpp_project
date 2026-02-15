#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr double eps = 1E-9;

void solve(){
  int n, k, h, w;
  std::cin >> n >> k >> h >> w;

  std::vector<std::array<int, 2>> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i][0] >> a[i][1];
  }

  auto check = [&](double x){
    std::vector<std::array<double, 2>> b;
    for(const auto& [p, v] : a){
      double r = v * x;
      if(r < h){
        continue;
      }

      r = std::sqrt(std::max(0., r * r - 1LL * h * h));
      b.push_back({p - r, p + r});
    }

    std::sort(b.begin(), b.end());

    if(b.size() == 0){
      return false;
    }

    double last = 0, R = -1;
    int cnt = 0;
    int m = b.size();

    for(const auto& [l, r] : b){
      if(l <= last){
        R = std::max(R, r);
      }else{
        cnt++;
        last = R;
        if(l > last || cnt > k){
          return false;
        }
        R = r;
      }
    }

    if(last < w){
      if(R < w){
        return false;
      }
      cnt++;
    }

    return cnt <= k;
  };

  double lo = 0, hi = w + h;
  while(hi - lo > eps){
    double mid = (lo + hi) / 2;
    if(check(mid)){
      hi = mid;
    }else{
      lo = mid;
    }
  }

  std::cout << std::fixed << std::setprecision(8) << (lo + hi) / 2 << "\n";
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