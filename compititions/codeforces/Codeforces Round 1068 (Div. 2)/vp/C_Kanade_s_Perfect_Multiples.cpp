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
  std::unordered_map<int,bool> has;
  for(int i = 0; i < n; i++){
    set.insert(a[i]);
    has[a[i]] = true;
  }

  std::vector<int> ans;
  while(set.size()){
    int min = *set.begin();
    ans.push_back(min);

    for(int i = min; i <= k; i += min){
      if(!has[i]){
        std::cout << "-1\n";
        return;
      }
      
      if(set.count(i)){
        set.erase(i);
      }
    }
  }

  std::cout << ans.size() << "\n";

  for(int i = 0; i < ans.size(); i++){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
  }
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