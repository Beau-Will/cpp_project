#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,k;
  std::cin >> n >> k;

  if((n-k) & 1){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> ans;
  for(int i = 0; i < n-k; i++){
    ans.push_back((i/2)+1);
  }
  for(int i = 0; i < k; i++){
    ans.push_back(i+n);
  }

  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i==ans.size()];
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