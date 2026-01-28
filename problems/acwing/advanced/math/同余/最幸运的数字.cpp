#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

template<typename T>
constexpr T geteuler(T n) {
  T res = n;
  for (T i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      res = res / i * (i - 1);
    }
  }
  if (n > 1) {
    res = res / n * (n - 1);
  }
  return res;
}

template<typename T>
constexpr T quickmul(T a, T b, T p) {
  T res = 0;
  for(; b; a = (a + a) % p, b >>= 1) {
    if(b & 1) {
      res = (res + a) % p;
    }
  }
  return res;
}

template<typename T>
constexpr T quickpower(T a, T b, T p) {
  T res = 1;
  for(; b; a = quickmul(a, a, p), b >>= 1) {
    if(b & 1) {
      res = quickmul(res, a, p);
    }
  }
  return res;
}

void solve(){
  int Ti = 1;
  i64 L;
  while(std::cin >> L) {
    if(L == 0){
      break;
    }

    i64 gcd = std::gcd(L, 8LL);
    i64 C = 9LL * L / gcd;
    i64 phi = geteuler(C);

    i64 ans = 1E18;

    if(C % 2 == 0 || C % 5 == 0) {
      ans = 0;
    }else{
      for(i64 d = 1; d <= phi/d; d++) {
        if(phi % d == 0) {
          if(quickpower(10LL, d, C) == 1) {
            ans = std::min(ans, d);
          }
          if(quickpower(10LL, phi / d, C) == 1) {
            ans = std::min(ans, phi / d);
          }
        }
      }
    }

    std::cout << "Case " << Ti++ << ": " << ans << "\n";
  }
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