#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::string> s(n);
  for(int i = 0; i < n; i++){
    std::cin >> s[i];
  }

  char c;
  std::cin >> c;

  auto g = std::vector(n,std::vector<int>(n));
  std::vector<int> cnt(n);
  int ans = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 1; k < std::min(s[i].size(),s[j].size()); k++){
        if(s[i].substr(s[i].size()-k,k) == s[j].substr(0,k)){
          g[i][j] = k;
          break;
        }
      }
    }
  }

  auto dfs = [&](auto &&self,std::string dragon,int last)->void {
    ans = std::max(ans,int(dragon.size()));

    cnt[last]++;

    for(int i = 0; i < n; i++){
      if(g[last][i] && cnt[i]<2){
        std::string tmp = dragon;
        dragon += s[i].substr(g[last][i]);

        self(self,dragon,i);

        dragon = tmp;
      }
    }

    cnt[last]--;
  };

  for(int i = 0; i < n; i++){
    if(s[i][0] == c){
      dfs(dfs,s[i],0);
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
  for(; T--;){
    solve();
  }

  return 0;
}