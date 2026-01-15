#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<std::pair<std::string,int>> a(n);
  std::unordered_map<std::string,int> map;

  for(int i = 0; i < n; i++){
    std::cin >> a[i].first >> a[i].second;

    map[a[i].first] += a[i].second;
  }

  int max = std::max_element(map.begin(),map.end(),[&](const auto& t1,const auto& t2){
    return t1.second < t2.second;
  })->second;

  std::unordered_map<std::string,int> map2;

  for(int i = 0; i < n; i++){
    map2[a[i].first] += a[i].second;

    if(map[a[i].first] == max && map2[a[i].first] >= max){
        std::cout << a[i].first << "\n";
        return;
    }
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }
}