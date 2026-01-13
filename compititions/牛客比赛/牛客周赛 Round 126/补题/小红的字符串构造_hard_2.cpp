#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::vector<std::string> s(n);
  for(int i = 0; i < n; i++){
    std::cin >> s[i];
  }

  int siz = 0;
  for(int i = 0; i < n; i++){
    siz += s[i].size();
  }

  auto trie = std::vector(siz+1,std::vector<int>(2));
  std::vector<int> cnt(siz+1);
  int idx = 0;

  auto insert = [&](const std::string &str){
    int p = 0;
    for(auto &c:str){
      int u = c-'0';
      if(!trie[p][u]){
        trie[p][u] = ++idx;
      }
      p = trie[p][u];
    }
    cnt[p]++;
  };

  for(int i = 0; i < n; i++){
    insert(s[i]);
  }

  auto query = [&](const std::string &str){
    int p = 0,res = 0;

    for(auto &c:str){
      int u = c-'0';
      if(!trie[p][u]){
        return -1;
      }
      
      p = trie[p][u];
      res += cnt[p];
    }
    return res;
  };

  for(int i = 0; i < n; i++){
    if(query(s[i]) == k){
      std::cout << s[i] << "\n";
      return;
    }
  }

  std::cout << "-1\n";
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