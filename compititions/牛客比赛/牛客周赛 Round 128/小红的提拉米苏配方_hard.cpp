#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s;
  std::cin >> s;

  int n = s.size();
  std::vector<int> pos;
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      pos.push_back(i);
    }
  }

  int m = pos.size();

  std::vector<bool> d(n);
  std::vector<bool> c(n);

  int j = m-1;
  for(int i = m-1; i >= 0; i--){
    int p = pos[i];
    if(p+1 < n && s[p+1]=='0' && j > i){
      d[p] = true;
      c[pos[j]] = true;
      j--;
    }
  }

  std::string ans;
  for(int i = 0; i < n; i++){
    if(d[i]){
      continue;
    }

    if(c[i]){
      ans += '2';
    }else{
      ans += s[i];
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

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}