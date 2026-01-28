#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

std::vector<int> minp, primes;

void sieve(int n) {
  minp.assign(n + 1, 0);  // 初始所有数的最小质因数为0（表示未处理）
  primes.clear();         // 清空质数列表

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {          // i是质数
      minp[i] = i;            // 质数的最小质因数是它自己
      primes.push_back(i);    // 加入质数列表
    }

    // 用当前数i去乘已发现的质数
    for (auto p : primes) {
      if (i * p > n) {   // 超出范围则终止
        break;
      }
      minp[i * p] = p;        // 标记i*p的最小质因数是p
      if (p == minp[i]) {// 关键：如果p是i的最小质因数，则跳出循环
        break;
      }
    }
  }
}

bool isprime(int n) {
  return minp[n] == n;
}

void solve(){
  int a,b,c,d;
  std::cin >> a >> b >> c >> d;

  int t = d;

  std::vector<std::array<int,2>> factor;

  for(int i = 0; primes[i] <= t/primes[i]; i++){
    int p = primes[i];
    if(t % p == 0){
      int s = 0;
      while(t % p == 0){
        t /= p;
        s++;
      }

      factor.push_back({p,s});
    }
  }
  if(t > 1){
    factor.push_back({t,1});
  }

  std::vector<int> dividor;

  std::function<void(int,int)> dfs = [&](int u,int p){
    if(u == factor.size()){
      dividor.push_back(p);
      return;
    }

    for(int i = 0; i <= factor[u][1]; i++){
      dfs(u+1,p);
      p *= factor[u][0];
    }
  };

  dfs(0,1);

  int ans = 0;
  for(int i = 0; i < dividor.size(); i++){
    int x = dividor[i];
    if(std::gcd(a,x) == b && std::lcm(c,x) == d){
      ans++;
    }
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  sieve(100000);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}