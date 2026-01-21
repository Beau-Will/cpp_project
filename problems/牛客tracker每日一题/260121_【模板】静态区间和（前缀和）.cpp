#include <iostream>
#include <vector>
#include <numeric>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n,q;
  std::cin >> n >> q;

  std::vector<i64> a(n+1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<i64> pre(n+1);
  std::partial_sum(a.begin(),a.end(),pre.begin());

  auto query = [&](int l,int r){
    return pre[r]-pre[l-1];
  };

  for(int i = 0; i < q; i++){
    int l,r;
    std::cin >> l >> r;

    std::cout << query(l,r) << "\n";
  }
}