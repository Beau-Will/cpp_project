#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void debug(){
  std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
  
  /* 
  生成一个数组
  */
  // int test_n = 10;
  // int test_ai = 1000;
  // int n = rnd()%test_n+1;
  // std::cout << n << "\n";
  // for(int i = 0; i < n; ++i){
  //   int ai = rnd()%test_ai+1;
  //   std::cout << ai << " \n"[i+1==n];
  // }

  /*
  生成一棵树
  */
  // int test_n = 10;
  // int n = rnd()%test_n+1;
  // for(int i = 2; i <= n; ++i){
  //   int fa = rnd()%(i-1)+1;
  //   std::cout << fa << " " << i << "\n";
  // }
}

void solve() {
  debug();
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}