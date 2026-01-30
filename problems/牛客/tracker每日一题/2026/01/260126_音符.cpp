#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,q;
  std::cin >> n >> q;

  std::vector<int> b(n);
  for(int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  std::vector<int> pre(n);
  std::partial_sum(b.begin(),b.end(),pre.begin());

  for(int qi = 0; qi < q; qi++){
    int t;
    std::cin >> t;

    int idx = std::upper_bound(pre.begin(),pre.end(),t)-pre.begin();
    std::cout << idx+1 << "\n";
  }
}