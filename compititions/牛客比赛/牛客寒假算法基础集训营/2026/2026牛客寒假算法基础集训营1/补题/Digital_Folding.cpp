#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

i64 reverse(std::string s){
  std::reverse(s.begin(), s.end());
  while(s.size() > 1 && s.back() == '0'){
    s.pop_back();
  }
  return std::stoll(s);
}

void solve(){
  i64 l, r;
  std::cin >> l >> r;

  std::string sl = std::to_string(l);
  std::string sr = std::to_string(r);

  i64 ans = reverse(sr);
  int d = sr.size() - sl.size();
  if(d){
    std::string t(sr.size(), '0');
    t.front() = '1';
    if(sr == t){
      sr = std::string(sr.size() - 1, '9');
      t.pop_back();
    }
    if(t.size() > sl.size()){
      sl = t;
    }
  }

  ans = std::max(ans, reverse(sr));

  std::string res(sr.size(), '?');
  bool isfirst = true;
  for(int i = 0; i < sr.size(); i++){
    int cl = sl[i], cr = sr[i];
    if(cl == cr && isfirst){
      res[i] = cr;
    }else if(cl != cr && isfirst){
      isfirst = false;
      res[i] = cr - 1;
    }else{
      res[i] = '9';
    }
  }

  ans = std::max(ans, reverse(res));

  std::cout << ans << "\n";
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