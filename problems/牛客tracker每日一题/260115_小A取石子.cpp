#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  int n,k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int xorSum = std::accumulate(a.begin(),a.end(),0,std::bit_xor<int>());

  if(xorSum){
    std::cout << "YES\n";
    return 0;
  }

  int max = *std::max_element(a.begin(),a.end());

  if(max < k){
    std::cout << "NO\n";
    return 0;
  }

  std::cout << (k?"YES\n":"NO\n");
}