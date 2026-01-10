#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,k,x;
  std::cin >> n >> k >> x;

  std::vector<i64> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::sort(a.begin(),a.end(),std::greater());

  i64 max = a[0]*k;
  
  std::vector<i64> d(n-1);
  for(int i = 0; i < n-1; i++){
    d[i] = a[0]-a[i+1];
  }

  using Node = std::tuple<i64,int,int>;

  std::priority_queue<Node,std::vector<Node>,std::greater<Node>> heap;
  heap.push({0,0,0});

  for(int i = 0; i < x; i++){
    auto [diff,last,t] = heap.top();
    heap.pop();

    std::cout << max-diff << "\n";
    if(t < k){
      for(int j = last; j < n-1; j++){
        heap.push({diff+d[j],j,t+1});
      }
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}