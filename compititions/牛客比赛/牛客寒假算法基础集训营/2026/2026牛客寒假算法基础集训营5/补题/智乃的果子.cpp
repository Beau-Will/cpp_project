#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  using Node = std::array<i64, 2>;
  std::priority_queue<Node, std::vector<Node>, std::greater<>> heap;
  for(int i = 0; i < n; i++){
    i64 c, w;
    std::cin >> c >> w;
    heap.push({w, c});
  }

  i64 ans = 0;
  while(heap.size()){
    auto [w1, c1] = heap.top();
    heap.pop();
    
    if(c1 > 1){
      (ans += ((w1 << 1) * (c1 >> 1)) % P1) %= P1;
      heap.push({w1 << 1, c1 >> 1});
      if(c1 & 1){
        heap.push({w1, 1});
      }
    }else if(heap.size()){
      auto [w2, c2] = heap.top();
      heap.pop();
      (ans += w1 + w2) %= P1;
      heap.push({w1 + w2, 1});
      if(c2 > 1){
        heap.push({w2, c2 - 1});
      }
    }else{
      break;
    }
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