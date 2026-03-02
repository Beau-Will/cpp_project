#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  std::string s, t;
  std::cin >> s >> t;

  std::string tmp1, tmp2;
  for(const auto& c : s){
    if(c == 'A'){
      continue;
    }
    tmp1 += c;
  }
  for(const auto& c : t){
    if(c == 'A'){
      continue;
    }
    tmp2 += c;
  }

  if(tmp1 != tmp2){
    std::cout << "-1\n";
    return;
  }

  std::vector<int> cnt1, cnt2;
  int cur1 = 0, cur2 = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A'){
      cur1++;
    }else{
      cnt1.push_back(cur1);
      cur1 = 0;
    }
  }
  cnt1.push_back(cur1);
  cur1 = 0;

  for(int i = 0; i < t.size(); i++){
    if(t[i] == 'A'){
      cur2++;
    }else{
      cnt2.push_back(cur2);
      cur2 = 0;
    }
  }
  cnt2.push_back(cur2);
  cur2 = 0;

  int ans = 0;
  for(int i = 0; i < cnt1.size(); i++){
    ans += std::abs(cnt1[i] - cnt2[i]);
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