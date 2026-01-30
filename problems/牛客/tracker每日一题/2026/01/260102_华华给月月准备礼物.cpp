#include <iostream>
#include <vector>

void solve(){
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  auto check = [&](int x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      cnt += a[i]/x;
    }
    return cnt >= k;
  };

  int l = 0, r = 1E9;
  while(l < r){
    int mid = (l+r+1)/2;

    if(mid!=0 && check(mid)){
      l = mid;
    }else{
      r = mid-1;
    }
  }

  std::cout << r << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for(; T--;){
    solve();
  }

  return 0;
}