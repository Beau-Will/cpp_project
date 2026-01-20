#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

  int n = rnd()%100+1;
  std::cout << n << "\n";

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    a[i] = rnd()%10000+1;
  }

  std::shuffle(a.begin(),a.end(),rnd);

  for(int i = 0; i < n; i++){
    std::cout << a[i] << " \n"[i+1==n];
  }
}