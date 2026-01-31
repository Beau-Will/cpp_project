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

std::vector<bool> isOne(1001);

void solve(){
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  for(int i = 0; i < n; i++){
    if(isOne[a[i]]){
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  sieve(1000);

  for(int i = 1; i <= 1000; i++){
    int cnt = 0;
    for(const auto& p : primes){
      if(p > i){
        continue;
      }
      if(i % p == 0){
        cnt++;
      }
    }
    if(cnt <= 1){
      isOne[i] = true;
    }
  }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}