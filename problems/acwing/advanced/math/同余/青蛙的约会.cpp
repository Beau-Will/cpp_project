#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T>
constexpr T exgcd(T a, T b, T& x, T& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  T d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}

void solve(){
  i64 sx, sy, m, n, L;
  std::cin >> sx >> sy >> m >> n >> L;

  i64 a = m - n, b = L;
  i64 x, y;

  i64 gcd = exgcd(a, b, x, y);

  if((sy - sx) % gcd){
    std::cout << "Impossible\n";
    return;
  }

  x *= (sy - sx) / gcd;

  int p = std::abs(L / gcd);

  std::cout << (x % p + p) % p << "\n";
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