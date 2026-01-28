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
  sieve(23);
  
  int n;
  std::cin >> n;

  int maxd = 0;
  int ans = 0;
  std::function<void(int,int,int,int)> dfs = [&](int u,int last,int p,int s){
    if(s > maxd || s == maxd && p < ans){
      maxd = s;
      ans = p;
    }
    if(u == 9){
      return;
    }

    for(int i = 1; i <= last; i++){
      if(1LL*p*primes[u] > n){
        break;
      }
      p *= primes[u];
      dfs(u+1,i,p,s*(i+1));
    }
  };

  dfs(0,30,1,1);

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