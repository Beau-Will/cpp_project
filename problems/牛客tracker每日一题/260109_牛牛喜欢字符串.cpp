#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  auto cnt = std::vector(k,std::vector<int>(26));

  for(int i = 0; i < n; i++){
    cnt[i%k][s[i]-'a']++;
  }

  int ans = 0;
  for(int i = 0; i < k; i++){
    int max = 0;

    for(int j = 0; j < 26; j++){
      max = std::max(max,cnt[i][j]);
    }
    
    ans += n/k-max;
  }

  std::cout << ans << "\n";
}
