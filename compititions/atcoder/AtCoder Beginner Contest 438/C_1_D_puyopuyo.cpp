#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  std::vector<int> stk;

  auto check = [&]()->bool {
    int t = stk.back();
    for(int i = stk.size()-1,j = 0; j < 4; i--,j++){
      if(stk[i]!=t){
        return false;
      }
    }
    return true;
  };

  for(int i = 0; i < n; i++){
    stk.push_back(a[i]);
    if(stk.size()>=4 && check()){
      for(int j = 0; j < 4; j++){
        stk.pop_back();
      }
    }
  }

  std::cout << stk.size() << "\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int T = 1;
  // std::cin >> T;
  for (; T--;) {
    solve();
  }

  return 0;
}