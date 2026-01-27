#include <bits/stdc++.h>

using i64 = long long;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::set<int> set;
  int max = *std::max_element(a.begin(),a.end());
  for(int i = 1; i <= max+n; i++){
    set.insert(i);
  }

  std::vector<int> ans(n);
  for(int i = 0; i < n; i++){
    if(set.count(a[i])){
      ans[i] = a[i];
      set.erase(a[i]);
    }else{
      int t = *set.lower_bound(a[i]);
      ans[i] = t;
      set.erase(t);
    }
  }

  for(int i = 0; i < n; i++){
    std::cout << ans[i] << " \n"[i+1==n];
  }
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