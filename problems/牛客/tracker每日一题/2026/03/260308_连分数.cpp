#include <iostream>

void solve(){
  int p, q;
  std::cin >> p >> q;

  auto work = [&](auto&& self) ->void {
    if(p % q == 0){
      std::cout << p / q;
    }else{
      std::cout <<  p / q << "+1/";
      p %= q;
      std::swap(p, q);
      bool isok = p % q;
      if(isok){
        std::cout << "{";
      }
      self(self);
      if(isok){
        std::cout << "}";
      }
    }
  };

  std::cout << p << "/" << q << " = ";
  work(work);
  std::cout << "\n";
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