#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;

struct Node{
  int id;
  int cnt;
  double money;
};

void solve() {
  int n;
  std::cin >> n;

  std::vector<Node> ans(n+1);
  for(int i = 1; i <= n; ++i){
    ans[i].id = i;
    ans[i].cnt = 0;
    ans[i].money = 0.0;
  }

  for(int i = 1; i <= n; ++i){
    int k;
    std::cin >> k;
    for(int j = 0; j < k; ++j){
      int id;
      double money;
      std::cin >> id >> money;
      money *= 0.01;
      ans[i].money -= money;
      ans[id].money += money;
      ++ans[id].cnt;
    }
  }

  double eps = 1e-8;
  std::sort(ans.begin()+1,ans.end(),[&](auto &t1,auto &t2){
    if(std::abs(t1.money-t2.money)>eps){
      return t1.money > t2.money;
    }
    if(t1.cnt!=t2.cnt){
      return t1.cnt > t2.cnt;
    }
    return t1.id < t2.id;
  });

  for(int i = 1; i <= n; ++i){
    std::cout << ans[i].id << " " << std::fixed << std::setprecision(2) << ans[i].money << "\n";
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