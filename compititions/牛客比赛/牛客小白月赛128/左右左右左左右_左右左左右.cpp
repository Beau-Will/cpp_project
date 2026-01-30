#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n, a0, a1;
  std::cin >> n >> a1 >> a0;

  std::string ans;
  i64 prev = 0;
  int cnt0 = 0,cnt1 = 0;
  if(a0 > a1){
    ans.push_back('1');
    prev += a1;
    cnt1++;
  }else{
    ans.push_back('0');
    prev -= a0;
    cnt0++;
  }

  for(int i = 1; i < n; i++){
    int t0 = std::abs(prev-a0);
    int t1 = std::abs(prev+a1);
    // std::cout << "i,t0,t1:" << i << " " << t0 << " " << t1 << "\n";
    if(t0 > t1){
      ans.push_back('1');
      prev += a1;
    }else{
      ans.push_back('0');
      prev -= a0;
    }
    // std::cout << "prev:" << prev << "\n";
  }

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