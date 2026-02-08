#include <iostream>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::multiset<int> set;
  for(int i = 0; i < n; i++){
    int x;
    std::cin >> x;
    set.insert(x);
  }

  int ans = 0;
  while(set.size()){
    int t = *set.begin();
    while(*set.lower_bound(t) == t){
      set.erase(set.lower_bound(t));
      t++;
    }
    ans++;
  }

  std::cout << ans << "\n";

  return 0;
}