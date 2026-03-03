#include <iostream>
#include <vector>
#include <map>

using i64 = long long;

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

  std::map<int, int> cnt;
  for(int i = 0; i < n; i++){
    if(a[i] == 0){
      std::cout << "NO\n";
      return 0;
    }
    cnt[a[i]]++;
  }

  for(const auto& [u, v] : cnt){
    if(cnt[-u] && cnt[u] + cnt[-u] == n){
      std::cout << "NO\n";
      return 0;
    }
  }

  std::cout << "YES\n";

  return 0;
}