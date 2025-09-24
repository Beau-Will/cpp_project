#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> a(n);
  for(int i = 0; i < n; ++i){
    int ki;
    std::cin >> ki;

    a[i].resize(ki);
    for(int j = 0; j < ki; ++j){
      std::cin >> a[i][j];
    }
  }

  std::vector<int> ans;

  while(a.size()){
    std::sort(a.begin(),a.end());
    ans.insert(ans.end(),a[0].begin(),a[0].end());

    int len = a[0].size();
    for(int i = 0; i < a.size(); ++i){
      if(a[i].size() <= len){
        std::swap(a[i],a.back());
        a.pop_back();
        --i;
        continue;
      }
      a[i].erase(a[i].begin(),a[i].begin()+len);
    }
  }

  for(int i = 0; i < ans.size(); ++i){
    std::cout << ans[i] << " \n"[i+1==ans.size()];
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