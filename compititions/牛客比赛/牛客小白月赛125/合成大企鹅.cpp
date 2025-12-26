#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<double> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::priority_queue<double,std::vector<double>,std::greater<double>> pq;
  for(int i = 0; i < n; i++){
    pq.push(a[i]);
  }

  while(pq.size()>1){
    auto t1 = pq.top();
    pq.pop();
    auto t2 = pq.top();
    pq.pop();

    pq.push(std::sqrt(t1*t2));
  }

  std::cout << std::fixed << std::setprecision(12) << pq.top() << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}