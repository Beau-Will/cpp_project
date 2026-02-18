#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<double> x(n), y(n);
  for(int i = 0; i < n; i++){
    std::cin >> x[i] >> y[i];
  }

  auto e = [&](int i){
    double x1 = x[i], y1 = y[i], x2 = x[i + 1], y2 = y[i + 1];
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };

  double ans = 0;
  for(int i = 0; i + 1 < n; i++){
    double t = std::max(0., std::log2(e(i) * std::log(2.)));
    ans += 2 * (t + e(i) / std::pow(2., t));
  }

  std::cout << std::fixed << std::setprecision(12) << ans << "\n";

  return 0;
}