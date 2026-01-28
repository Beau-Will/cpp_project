#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> minp, primes;
std::vector<i64> phi;

void sieve(int n) {
  minp.assign(n + 1, 0);
  phi.assign(n + 1, 0);
  primes.clear();

  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      phi[i] = i - 1;
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
    }
  }
  
  std::partial_sum(phi.begin(),phi.end(),phi.begin());
}

bool isprime(int n) {
  return minp[n] == n;
}

void solve(){
  int n;
  std::cin >> n;

  sieve(n);

  i64 ans = 0;
  for(const auto& p:primes){
    ans += (phi[n/p]-1)*2+1;
  }

  std::cout << ans << "\n";
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