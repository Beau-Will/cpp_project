#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto b = a;
  // std::sort(b.begin(),b.end());
  // b.erase(std::unique(b.begin(),b.end()),b.end());

  int ans = 0;

  for(const auto& ele:b){
    auto c = a;

    for(int i = 0; i < n; i++){
      a[i] += -ele;
    }

    std::unordered_map<int,int> cnt;
    for(int i = 0; i < n; i++){
      cnt[a[i]]++;
    }
    for(int i = 0; i <= n; i++){
      if(!cnt[i]){
        ans = std::max(ans,i);
        break;
      }
    }

    a = c;
  }

  std::cout << ans << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for(; T--;){
    solve();
  }
}