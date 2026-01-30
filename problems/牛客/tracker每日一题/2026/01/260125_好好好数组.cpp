#include <iostream>
#include <vector>
#include <map>

void solve(){
  int n,m;
  std::cin >> n >> m;

  if(m == 1){
    std::cout << n+m << "\n";
  }else if(m == 2){
    std::cout << n << "\n";
  }else if(m == 3){
    std::cout << "1\n";
  }else{
    std::cout << "0\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // 打表
  // std::vector<int> a(11);
  // for(int ni = 1; ni <= 10; ni++){
  //   for(int mi = 1; mi <= ni; mi++){
  //     int ans = 0;
  //     for(int i = 0; i <= ni; i++){
  //       a[ni] = i;
  //       std::map<int,int> map;
  //       map[a[ni]]++;
  //       for(int j = ni-1; j >= 1; j--){
  //         a[j] = a[j+1]%j;
  //         map[a[j]]++;
  //       }
  //       if(map.size() >= mi){
  //         ans++;
  //       }
  //     }
  //     std::cout << "n,m:" << ni << "," << mi << "\n";
  //     std::cout << "ans:" << ans << "\n";
  //   }
  // }

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }
}