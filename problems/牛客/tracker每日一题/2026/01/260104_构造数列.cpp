#include <iostream>

void solve(){
  int n;
  std::cin >> n;
  
  if((n/2)&1){
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";

  for(int i = 1; i <= n/2; i++){
    std::cout << i*2 << " ";
  }
  
  for(int i = 1; i <= n/2; i++){
    if(i != n/2){
      std::cout << i*2-1 << " ";
    }else{
      std::cout << i*2-1+n/2 << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(; T--;){
    solve();
  }
}