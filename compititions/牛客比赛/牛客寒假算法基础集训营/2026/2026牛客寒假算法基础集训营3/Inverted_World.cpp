#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::string t0, t1;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    t0 += char('0' + (cnt & 1));
    t1 += char('0' + ((cnt + 1) & 1));
    cnt++;
  }

  int cnt0 = 0, cnt1 = 0;
  for(int i = 0; i < n; i++){
    if(s[i] != t0[i]){
      cnt0++;
    }
    if(s[i] != t1[i]){
      cnt1++;
    }
  }

  int ans = std::min(cnt0, cnt1);

  if(!count(s.begin(), s.end(), '0') || !std::count(s.begin(), s.end(), '1') || ans == 0){
    std::cout << ans << "\n";
    return;
  }

  std::vector<int> tmp0, tmp1;
  for(int i = 0; i < n; i++){
    if(s[i] != t0[i]){
      tmp0.push_back(s[i] - '0');
    }
    if(s[i] != t1[i]){
      tmp1.push_back(s[i] - '0');
    }
  }

  cnt0 = 0, cnt1 = 0;
  int k = 0;
  for(const auto& x : tmp0){
    if(x == 0){
      if(cnt1 > 0){
        cnt1--;
      }
      cnt0++;
    }else{
      if(cnt0 > 0){
        cnt0--;
      }
      cnt1++;
    }
    k = std::max(k, cnt0 + cnt1);
  }

  ans = std::min(ans, k);

  cnt0 = 0, cnt1 = 0, k = 0;

  for(const auto& x : tmp1){
    if(x == 0){
      if(cnt1 > 0){
        cnt1--;
      }
      cnt0++;
    }else{
      if(cnt0 > 0){
        cnt0--;
      }
      cnt1++;
    }
    k = std::max(k, cnt0 + cnt1);
  }

  ans = std::min(ans, k);

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