#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

using i64 = long long;

struct DSU{
  std::vector<int> f, siz;
  std::vector<i64> sum;

  DSU(int n, const std::vector<int>& init){
    f.resize(n + 1);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n + 1, 1);
    sum.assign(init.size(), 0);
    for(int i = 1; i < init.size(); i++){
      sum[i] = init[i];
    }
  }

  int find(int x){
    if(x != f[x]){
      f[x] = find(f[x]);
    }
    return f[x];
  }

  bool merge(int u, int v){
    int fu = find(u), fv = find(v);
    if(fu == fv){
      return false;
    }
    if(u > v){
      std::swap(u, v);
    }
    f[fu] = fv;
    siz[fv] += siz[fu];
    sum[fv] += sum[fu];
    return true;
  }

  bool same(int u, int v){
    return find(u) == find(v);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  DSU dsu(n + 1, a);

  for(int mi = 0; mi < m; mi++){
    int op;
    std::cin >> op;

    if(op == 1){
      int l, r;
      std::cin >> l >> r;
      for(int i = dsu.find(l); i < r; i = dsu.find(i)){
        dsu.merge(i, i + 1);
        dsu.f[i] = dsu.find(i + 1);
      }
    }else{ // op == 2
      int x;
      std::cin >> x;
      int fx = dsu.find(x);
      std::cout << std::fixed << std::setprecision(10) << 1. * dsu.sum[fx] / dsu.siz[fx] << "\n";
    }
  }

  return 0;
}