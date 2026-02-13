#include <bits/stdc++.h>

using i64 = long long;
using f128 = long double;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr f128 eps = 1E-12;

void solve(){
  int n, w;
  std::cin >> n >> w;

  std::vector<i64> x(n), y(n);
  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i];
  }

  std::vector<int> t(n , 0);
  f128 sum = 0.L;
  for(int i = 0; i < n; i++){
    sum += std::sqrt(1.L * x[i] * x[i] + 1.L * y[i] * y[i]);
  }

  using Node = std::tuple<f128, int, int>;
  std::priority_queue<Node> heap;
  
  for(int i = 0; i < n; i++){
    if(y[i] > 0){
      f128 tmp = (2.L * y[i] - 1.L) / (std::sqrt(1.L * x[i] * x[i] + 1.L * y[i] * y[i]) + std::sqrt(1.L * x[i] * x[i] + 1.L * (y[i] - 1) * (y[i] - 1)));
      if(tmp > eps){
        heap.push({tmp, 0, i});
      }
    }
  }

  while(w > 0 && heap.size()){
    auto [wi, ti, idx] = heap.top();
    heap.pop();

    if(ti != t[idx]){
      continue;
    }

    t[idx]++;
    sum -= wi;
    w--;

    if(t[idx] < y[idx]){
      i64 d = y[idx] - t[idx];
      f128 tmp = (2.L * d - 1.L) / (std::sqrt(1.L * x[idx] * x[idx] + 1.L * d * d) + std::sqrt(1.L * x[idx] * x[idx] + 1.L * (d - 1) * (d - 1)));

      if(tmp > eps){
        heap.push({tmp, t[idx], idx});
      }
    }
  }

  std::cout << std::fixed << std::setprecision(9) << sum << "\n";
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