#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7,P2 = 998244353;

void solve(){
  int n;
  std::cin >> n;

  std::unordered_map<std::string,int> cnt;
  for(int i = 0; i < n; i++){
    std::string s;
    std::cin >> s;

    if(!cnt[s]){
        cnt[s]++;
        std::cout << "OK\n";
    }else{
        std::cout << s << (cnt[s]++) << "\n";
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