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

  auto insert = [&](const std::string &s){
    int p = 0;
    for(auto &c:s){
      int t = c-'0';
      if(!trie[p][t]){
        trie[p][t] = ++idx;
      }
      p = trie[p][t];
    }
    cnt[p]++;
  };

  for(int i = 0; i < n; i++){
    insert(s[i]);
  }

  std::string ans;
  int sum = 0;
  bool isok = false;

  auto dfs = [&](auto &&self,int cur)->void {
    if(isok){
      return;
    }
    if(sum == k){
      isok = true;
      std::cout << ans << "\n";
    }else if(sum > k){
      return;
    }

    if(trie[cur][0]){
      ans += '0';
      sum += cnt[trie[cur][0]];
      self(self,trie[cur][0]);
      ans.pop_back();
      sum -= cnt[trie[cur][0]];
    }
    if(trie[cur][1]){
      ans += '1';
      sum += cnt[trie[cur][1]];
      self(self,trie[cur][1]);
      ans.pop_back();
      sum -= cnt[trie[cur][1]];
    }
  };

  dfs(dfs,0);

  if(!isok){
    std::cout << "-1\n";
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