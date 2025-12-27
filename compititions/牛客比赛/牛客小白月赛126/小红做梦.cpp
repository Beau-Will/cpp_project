#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  i64 x;
  int a,b,c;
  std::cin >> x >> a >> b >> c;

  std::priority_queue<std::pair<i64,i64>,std::vector<std::pair<i64,i64>>,std::greater<>> pq;

  int cnt = 0;
  pq.push({0,x});
  while(x){
    x /= 10;
    cnt++;
    pq.push({cnt*a,x});
  }

  while(pq.size()){
    auto [w,_x] = pq.top();
    pq.pop();
    i64 y = _x;
    while(y>1010){
      y /= 10;
    }
    if(y>=1005 && y<=1010){
      std::cout << w << "\n";
      return;
    }
    pq.push({w+b,_x+c});
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}