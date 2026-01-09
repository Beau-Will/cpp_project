#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::set<int> set;
  for(int i = 0; i <= n+1; i++){
    set.insert(i);
  }

  for(int i = 0; i < n; i++){
    if(set.count(a[i])){
      set.erase(a[i]);
    }
  }

  int mex = *set.begin();

  std::cout << std::min(mex,k-1) << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}