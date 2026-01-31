#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using d128 = long double;

constexpr int inf1 = 1'000'000'000, P = 131;//P = 13331;
constexpr int P1 = 1'000'000'007, P2 = 998'244'353;
constexpr int inf2 = 0x3f3f3f3f;
constexpr i64 inf3 = 1'000'000'000'000'000'000;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define fi first
#define se second

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<char> stk;
  for(int i = 0; i < n; ++i){
    if(stk.empty()){
      stk.push_back(s[i]);
    }else{
      if(s[i]>='a'){//小写
        if(s[i]<'n'||stk.back()<'a'||stk.back()>'m'){
          stk.push_back(s[i]);
          continue;
        }
        if(stk.back()-'a'=='z'-s[i]){
          stk.pop_back();
        }else{
          stk.push_back(s[i]);
        }
      }else{//大写
        if(s[i]>'M'||stk.back()>='a'||stk.back()<'N'){
          stk.push_back(s[i]);
          continue;
        }
        if('Z'-stk.back()==s[i]-'A'){
          stk.pop_back();
        }else{
          stk.push_back(s[i]);
        }
      }
    }
    // if(!stk.empty()){
    //   // std::cout << stk.back() << " \n"[i+1==n];
    //   for(int i = 0; i < stk.size(); ++i){
    //     std::cout << stk[i];
    //   }
    //   std::cout << "\n";
    // }
  }

  std::cout << stk.size() << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int _t = 1;
  // std::cin >> _t;
  for (; _t--;) {
    solve();
  }

  return 0;
}