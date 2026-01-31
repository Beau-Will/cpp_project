#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::string a,b;
  std::cin >> a >> b;

  int num1 = 0,num2 = 0;
  for(char c:a){
    if(c!='+'){
      num1 = num1*10+c-'0';
    }
  }
  for(char c:b){
    if(c!='+'){
      num2 = num2*10+c-'0';
    }
  }
  if(num1>num2){
    std::cout << "Yes\n";
    return;
  }
  if(num1<num2){
    std::cout << "No\n";
  }

  if(num1==num2){
    if(a.back()=='+'){
      std::cout << "Yes\n";
    }else{
      std::cout << "No\n";
    }
  }
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