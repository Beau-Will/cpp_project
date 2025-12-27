#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1E9,inf2 = 0x3f3f3f3f;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve() {
  int n,m,k;
  std::cin >> n >> m >> k;

  std::unordered_map<std::string,i64> map;
  for(int i = 0; i < n; i++){
    std::string s;
    int t;
    std::cin >> s >> t;
    map[s] = t;
  }

  std::unordered_map<std::string,bool> vis;
  for(int i = 0; i < k; i++){
    std::string s;
    std::cin >> s;
    vis[s] = true;
  }

  i64 max = 1E18;
  for(auto [u,v]:vis){
    max = std::min(max,map[u]);
  }

  i64 rest = (m-k)*max;
  i64 cnt1 = 0,cnt2 = 0;
  for(auto [u,v]:map){
    if(!vis[u]){
      cnt1 += v;
    }else{
      cnt2 += v;
    }
  }
  if(rest<cnt1 || (m-1)*max<cnt1+cnt2-max){
    std::cout << "-1\n";
    return;
  }

  i64 min = (cnt1+cnt2)/m + ((cnt1+cnt2)%m!=0?1:0);

  std::cout << min << " " << max << "\n";
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