#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  if(n == 1){
    std::cout << "-1\n";
    return 0;
  }

  if(a[1] == a[n]){
    std::cout << "1\n";
    return 0;
  }

  for(int i = 2; i+1 <= n-1; i++){
    if(a[1] == a[i] && a[i+1] == a[n]){
      std::cout << "2\n";
      return 0;
    }
  }

  std::cout << "-1\n";
}