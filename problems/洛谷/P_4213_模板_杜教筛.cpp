#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr int N = 1E6;

using Z = i64;

template<typename T>
std::map<T, Z> fMu;

template<typename T>
std::map<T, Z> fPhi;

std::vector<int> minp, primes, phi, mu;
std::vector<i64> sphi;

void sieve(int n) {
  minp.assign(n + 1, 0);
  phi.assign(n + 1, 0);
  sphi.assign(n + 1, 0);
  mu.assign(n + 1, 0);
  primes.clear();
  phi[1] = 1;
  mu[1] = 1;

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      phi[i] = i - 1;
      mu[i] = -1;
      primes.push_back(i);
    }

    for (auto p : primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * (p - 1);
      mu[i * p] = -mu[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    sphi[i] = sphi[i - 1] + phi[i];
    mu[i] += mu[i - 1];
  }
}

template<typename T>
Z sumPhi(int n) {
  if (n <= N) {
    return sphi[n];
  }
  if (fPhi<T>.count(n)) {
    return fPhi<T>[n];
  }
  if (n == 0) {
    return 0;
  }
  Z ans = Z(n) * (Z(n) + 1) / 2;
  for (i64 l = 2, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans -= (r - l + 1) * sumPhi<T>(n / l);
  }
  return fPhi<T>[n] = ans;
}

template<typename T>
Z sumMu(int n) {
  if (n <= N) {
    return mu[n];
  }
  if (fMu<T>.count(n)) {
    return fMu<T>[n];
  }
  if (n == 0) {
    return 0;
  }
  Z ans = 1;
  for (i64 l = 2, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans -= (r - l + 1) * sumMu<T>(n / l);
  }
  return fMu<T>[n] = ans;
}

void solve(){
  int n;
  std::cin >> n;

  std::cout << sumPhi<i64>(n) << " " << sumMu<i64>(n) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  sieve(N);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}