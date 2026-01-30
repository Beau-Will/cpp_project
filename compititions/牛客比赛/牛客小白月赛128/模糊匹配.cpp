#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s,t;
  std::cin >> s >> t;

  bool issame = true;
  for(int i = 0; i < n; i++){
    char si = s[i];
    char ti = t[i];
    if(si == 'O' && ti == '0' || si == '0' && ti == 'O'){
      continue;
    }
    if(si == 'I' || si == 'l' || si == '1'){
      if(ti == 'I' || ti == 'l' || ti == '1'){
        continue;
      }
    }
    if(si != ti){
      issame = false;
      break;
    }
  }

  std::cout << (issame?"YES\n":"NO\n");
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}