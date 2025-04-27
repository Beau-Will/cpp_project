#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf1 = 1'000'000'000, P = 131;
constexpr int P1 = 1'000'000'007, P2 = 998244353;
constexpr i64 inf2 = 1'000'000'000'000'000'000;
constexpr int inf3 = 0x3f3f3f3f;
const double pi = std::acos(-1.0);

#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define debug(x) std::cout << #x << ":" << x << "\n"

void solve() {
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> a[i];
  }

  std::vector<int> b(n+1);
  for(int i = 1; i <= n; ++i){
    std::cin >> b[i];
  }

  bool flag = true;
  // auto check = [&](){
    int t = -1;
    for(int i = 1; i <= n; ++i){
      if(b[i]!=-1){
        if(t==-1){
          t = a[i]+b[i];
        }else{
          if(t!=a[i]+b[i]){
            flag = false;
          }
        }
      }
    }
    // return true;
  // };

  // if(!check()){
  //   std::cout << 0 << "\n";
  //   return;
  // }
  if(!flag){
    std::cout << 0 << "\n";
    return;
  }

  if(t==-1){
    int max = *max_element(a.begin()+1,a.end());
    int min = *min_element(a.begin()+1,a.end());

    std::cout << k-(max-min)+1 << "\n";
    return;
  }

  for(int i = 1; i <= n; ++i){
    if(b[i]==-1){
      if(t-a[i]>k || t-a[i]<0){
        std::cout << 0 << "\n";
        return;
      }
    }
  }
  
  std::cout << 1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 1;
  std::cin >> t;
  for (; t--;) {
    solve();
  }

  return 0;
}