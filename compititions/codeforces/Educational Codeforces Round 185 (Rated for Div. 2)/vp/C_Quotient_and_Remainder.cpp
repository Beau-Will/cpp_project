#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr i64 inf2 = 1E18;

void solve(){
  int n;
  i64 k;
  std::cin >> n >> k;

  std::vector<i64> a(n+1),b(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    std::cin >> b[i];
  }

  std::sort(a.begin()+1,a.end());
  std::sort(b.begin()+1,b.end());

  auto check = [&](int idx){
    for(int i = 1; i <= idx; i++){
      //a[i]
      //b[idx-i+1]
      i64 y = b[idx-i+1]+1;
      i64 x = y*a[i]+b[idx-i+1];

      if(x > k){
        return false;
      }
    }
    return true;
  };

  int l = 0,r = n;
  while(l < r){
    int mid = (l+r+1)/2;

    if(check(mid)){
      l = mid;
    }else{
      r = mid-1;
    }
  }

  std::cout << l << "\n";
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

  return 0;
}