#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> f;

void solve(){
  int x, l, r;
  std::cin >> x >> l >> r;

  std::map<int, int> fac;
  int tmp = x;
  for(int i = 2; i <= tmp / i; i++){
    if(tmp % i){
      continue;
    }
    int cnt = 0;
    while(tmp % i == 0){
      tmp /= i;
      cnt++;
    }
    fac[i] = cnt;
  }
  if(tmp != 1){
    fac[tmp] = 1;
  }

  int t = 1;
  for(const auto& [u, v] : fac){
    // std::cout << "[u, v]: " << u << ", " << v << "\n";
    if(v & 1){
      t *= u;
    }
  }

  auto isok = [&](int y){
    i64 res = 1LL * x * y;
    i64 tt = std::sqrt(res);

    return tt * tt == res;
  };

  for(int i = 0; i < f.size(); i++){
    if(1LL * f[i] * t < l){
      continue;
    }
    if(1LL * f[i] * t > r){
      break;
    }
    if(isok(f[i] * t)){
      std::cout << f[i] * t << "\n";
      return;
    }
  }

  std::cout << "-1\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  for(int i = 1; i <= 1000; i++){
    f.push_back(i * i);
  }

  int T = 1;
  // std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}