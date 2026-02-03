#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;

struct DSU {
  int _n;
  std::vector<int> _fa, _size;
  DSU() {}
  DSU(int n) {
    init(n);
  }
  void init(int n) {
    _fa.resize(n);
    std::iota(_fa.begin(), _fa.end(), 0);
    _size.assign(n, 1);
  }
  int find(int x) {
    if (x != _fa[x]) {
      _fa[x] = find(_fa[x]);
    }
    return _fa[x];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      _size[fx] += _size[fy];
      _fa[fy] = fx;
      return true;
    }
    return false;
  }
};

void solve(){
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<std::tuple<int, int, int>> edges;
  std::map<std::pair<int, int>, bool> vis;

  for(int mi = 0; mi < m; mi++){
    int u, v;
    std::cin >> u >> v;

    if(v < u){
      std::swap(u, v);
    }
    vis[{u, v}] = true;
  }
  // for(const auto& [t, isok] : vis){
  //   auto [u, v] = t;
  //   std::cout << "u, v, isok:" << u << "," << v << "," << isok << "\n";
  // }

  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(vis[{i, j}]){
        continue;
      }
      edges.push_back({a[i] + a[j], i, j});
    }
  }

  // for(const auto& [w, u, v] : edges){
  //   std::cout << "w, u, v:" << w << "," << u << "," << v << "\n";
  // }

  auto kruskal = [&](){
    std::sort(edges.begin(), edges.end());

    DSU dsu(n + 1);
    i64 ans = 0, cnt = 0;
    for(const auto& [w, u, v] : edges){
      if(dsu.merge(u, v)){
        ans += w;
        cnt++;
      }
      if(cnt == n - 1){
        break;
      }
    }
    return (cnt == n - 1? ans: -1LL);
  };

  std::cout << kruskal() << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 1;
  std::cin >> T;

  for(int Ti = 0; Ti < T; Ti++){
    solve();
  }

  return 0;
}