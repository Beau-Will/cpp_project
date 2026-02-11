#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<i64> c(n), w(n);
  for(int i = 0; i < n; i++){
    std::cin >> c[i] >> w[i];
  }

  i64 ans = 0;
  using pll = std::pair<i64, i64>;

  std::priority_queue<pll, std::vector<pll>, std::greater<>> heap;
  for(int i = 0; i < n; i++){
    heap.push({w[i], c[i]});
  }

  while(heap.size()){
    auto [wi, ci] = heap.top();
    heap.pop();
    if(heap.empty()){
      if(ci == 0){
        break;
      }
      i64 t = 1, cnt = 0;
      while(t < ci){
        t *= 2;
        cnt++;
      }
      i64 tmp = ci * cnt + ci - t;
      ans = (ans + (wi % P1) * (tmp % P1) % P1) % P1;
      break;
    }
    if(ci == 1){
      auto [wj, cj] = heap.top();
      heap.pop();
      ans = (ans + (wi + wj) % P1) % P1;
      heap.push({wi + wj, 1});
      cj--;
      if(cj > 0){
        heap.push({wj, cj});
      }
    }else{
      ans = (ans + ((wi * 2) % P1 * (ci / 2 % P1) % P1)) % P1;
      heap.push({wi * 2, ci / 2});
      ci %= 2;
      if(ci > 0){
        heap.push({wi, ci});
      }
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