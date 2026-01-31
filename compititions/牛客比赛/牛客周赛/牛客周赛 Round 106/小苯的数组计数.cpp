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
  for(int i = 0; i < n; ++i){
    std::cin >> a[i];
  }

  int ans = 0;
  std::vector<int> stk;

  for(int i = 0; i < n; ++i){
    bool flag = false;
    while(!stk.empty()&&a[stk.back()]<=a[i]){
      if(a[stk.back()]==a[i]){
        flag = true;
      }
      stk.pop_back();
    }
    if(!stk.empty()&&stk.back()<i-1&&!flag){
      ++ans;
    }
    stk.push_back(i);
  }

  stk.clear();

  for(int i = n-1; i >= 0; --i){
    bool flag = false;
    while(!stk.empty()&&a[stk.back()]<=a[i]){
      if(a[stk.back()]==a[i]){
        flag = true;
      }
      stk.pop_back();
    }
    if(!stk.empty()&&stk.back()>i+1&&!flag){
      ++ans;
    }
    stk.push_back(i);
  }

  std::cout << ans << "\n";
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