#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  int k;
  std::cin >> k;

  int ans = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(a[i]){
      if(cnt){
        ans += (cnt - 1) / 2;
        cnt = 0;
      }
    }else{
      cnt++;
    }
  }
  if(cnt){
    ans += (cnt - 1) / 2;
  }

  std::cout << (ans >= k ? "true\n" : "false\n");

  return 0;
}