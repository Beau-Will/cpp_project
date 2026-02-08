#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;

  std::vector<std::tuple<std::string, double>> a(m);
  for(int i = 0; i < m; i++){
    auto& [name, score] = a[i];
    std::cin >> name;
    
    std::string t;
    std::cin >> t;
    int cnt = 0;
    for(int j = 0; j < n; j++){
      if(s[j] == t[j]){
        cnt++;
      }
    }
    score = 100. * cnt / n;
  }

  constexpr double eps = 1E-8;

  std::sort(a.begin(), a.end(), [](const auto& p1, const auto& p2){
    const auto& [name1, score1] = p1;
    const auto& [name2, score2] = p2;

    if(std::abs(score1 - score2) < eps){
      return name1 < name2;
    }
    return score1 > score2;
  });

  const auto& [name, score] = a.front();

  std::cout << name << "\n";
  std::cout << std::fixed << std::setprecision(2) << score << "\n";

  return 0;
}