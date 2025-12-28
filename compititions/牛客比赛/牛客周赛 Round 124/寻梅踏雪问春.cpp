#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  std::vector<std::pair<int,int>> a(3);

  for(int i = 0; i < 3; i++){
    std::cin >> a[i].first >> a[i].second;
  }

  // std::sort(a.begin(),a.end());

  auto get = [&](std::pair<int,int> &p1,std::pair<int,int> &p2){
    return 1LL*(p1.first-p2.first)*(p1.first-p2.first)+1LL*(p1.second-p2.second)*(p1.second-p2.second);
  };

  if(get(a[0],a[1])==get(a[0],a[2]) && get(a[0],a[1])==get(a[1],a[2])){
    std::cout << "YES\n";
  }else{
    std::cout << "NO\n";
  }
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