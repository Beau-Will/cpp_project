#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto check = [&](std::string &str){
    std::string t = str+str;
    bool flag1 = true,flag2 = true;
    for(int i = 0; i+1 < str.size(); i+=2){
      if(t[i]!=t[i+1]){
        flag1 = false;
        break;
      }
    }
    for(int i = 0; i+1 <= str.size(); i+=2){
      if(t[i]!=t[i+1]){
        flag2 = false;
        break;
      }
    }
    return (flag1==false && flag2==false?false:true);
  };

  if(!check(s)){
    std::cout << "-1\n";
    return;
  }

  i64 sum1 = 0,sum2 = 0;
  std::string t = s+s;

  for(int i = 0; i+1 < s.size(); i+=2){
    sum1 += a[i]*a[i+1];  
  }

  for(int i = 1; i+1 <= s.size(); i+=2){
    sum2 += a[i]*a[(i+1==s.size()?0:i+1)];
  }

  std::cout << std::max(sum1,sum2) << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}