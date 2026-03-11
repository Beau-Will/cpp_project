#include <iostream>

void solve(){
  int a, b;
  std::cin >> a >> b;

  if(b > a){
    std::swap(a, b);
  }

  auto check = [&](int x){
    int sum = x * x;
    int cnt1 = (sum + 1) / 2;
    int cnt2 = sum / 2;
    return cnt1 >= a && cnt2 >= b;
  };

  int l = 1, r = 45000;
  while(l < r){
    int mid = (l + r) >> 1;
    if(check(mid)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }

  std::cout << l << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}