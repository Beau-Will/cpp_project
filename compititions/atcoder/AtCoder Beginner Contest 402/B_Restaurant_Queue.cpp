#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

void solve() {
  int n;
  std::cin >> n;

  std::queue<int> q;
  while(n--){
    int op;
    std::cin >> op;

    if(op==1){
      int x;
      std::cin >> x;

      q.push(x);
    }else{
      if(q.size()){
        std::cout << q.front() << "\n";
        q.pop();
      }
    }
  }
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