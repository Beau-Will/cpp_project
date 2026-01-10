#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

void solve(){
  int n,q;
  std::cin >> n >> q;

  std::vector<int> a(n+1);

  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }
  
  std::sort(a.begin()+1,a.end());

  for(int qi = 0; qi < q; qi++){
    int x,y;
    std::cin >> x >> y;

    i64 l = x+y-1,r = x+n+y-1;
    while(l < r){
      i64 mid = (l+r)>>1;

      i64 diff = mid-x+1-y;
      int d = std::upper_bound(a.begin()+1,a.end(),mid)-std::lower_bound(a.begin()+1,a.end(),x);

      if(diff >= d){
        r = mid;
      }else{
        l = mid+1;
      }
    }
    
    std::cout << l << "\n";
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