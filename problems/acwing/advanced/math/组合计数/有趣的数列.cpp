#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> minp, primes;

void sieve(int n) {
  minp.assign(n + 1, 0);
  primes.clear();

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }

    for (auto p : primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }
}

bool isprime(int n) {
  return minp[n] == n;
}

template<typename T>
T power(T a, T b, T p){
  T res = 1;
  for(; b; a = static_cast<__int128>(a) * a % p, b >>= 1){
    if(b & 1){
      res = static_cast<__int128>(res) * a % p;
    }
  }
  return res;
}

void solve(){
  int n, P;
  std::cin >> n >> P;

  sieve(2 * n);

  auto get = [&](int n, int p){
    int res = 0;
    while(n){
      res += n/p;
      n /= p;
    }
    return res;
  };

  auto C = [&](int n, int m){
    int res = 1;
    for(const auto& p : primes){
      int s = get(n, p) - get(m, p) - get(n - m, p);
      res = (static_cast<i64>(res) * power(p, s, P)) % P;
    }
    return res;
  };

  std::cout << (C(2 * n, n) - C(2 * n, n - 1) + P) % P << "\n";
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