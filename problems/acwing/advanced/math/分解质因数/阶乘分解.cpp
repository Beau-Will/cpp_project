#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> minp,primes;

void sieve(int n){
  primes.clear();
  minp.assign(n+1,0);

  for(int i = 2; i <= n; i++){
    if(minp[i] == 0){
      minp[i] = i;
      primes.push_back(i);
    }

    for(const auto& p:primes){
      if(i * p > n){
        break;
      }
      minp[i*p] = p;
      if(p == minp[i]){
        break;
      }
    }
  }
}

bool isprime(int n){
  return minp[n]==n;
}

void solve(){
  int n;
  std::cin >> n;

  sieve(n);
  
  std::map<int,int> cnt;
  for(const auto& p:primes){
    i64 t = p;
    while(t <= n){
      cnt[p] += n/t;
      t *= p;
    }
  }

  for(const auto& [u,v]:cnt){
    if(v == 0){
      continue;
    }
    std::cout << u << " " << v << "\n";
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