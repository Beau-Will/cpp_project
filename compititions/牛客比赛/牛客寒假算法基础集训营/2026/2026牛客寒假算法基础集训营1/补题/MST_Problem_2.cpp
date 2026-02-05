#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf1 = 1E9;
constexpr i64 inf2 = 1E18;
constexpr int P1 = 1E9+7, P2 = 998'244'353;
constexpr int inf = 2E9 + 10;

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

  std::vector<i64> a(n + 1);
  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  std::vector<std::vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  i64 ans = 0;
  DSU dsu(n + 1);

  auto boruvka = [&](){
    std::multiset<std::pair<i64, int>> set;
    for(int i = 1; i <= n; i++){
      set.insert({a[i], i});
    }
    std::vector<std::vector<int>> id(n + 1);
    for(int i = 1; i <= n; i++){
      id[dsu.find(i)].push_back(i);
    }
    i64 cnt = 0;
    for(int i = 1; i <= n; i++){
      for(const auto& u : id[i]){
        set.erase({a[u], u});
      }
      i64 min = 1E18, p = 0;
      for(const auto& u : id[i]){
        for(const auto& v : adj[u]){
          if(dsu.find(u) == dsu.find(v)){
            continue;
          }
          set.erase({a[v], v});
        }
        if(set.size()){
          auto [amin, idx] = *set.begin();
          if(a[u] + amin < min){
            min = a[u] + amin;
            p = idx;
          }
        }
        for(const auto& v : adj[u]){
          if(dsu.find(u) == dsu.find(v)){
            continue;
          }
          set.insert({a[v], v});
        }
      }
      if(p && dsu.find(i) != dsu.find(p)){
        cnt++;
        ans += min;
        dsu._fa[dsu.find(i)] = dsu.find(p);
      }
      for(const auto& u : id[i]){
        set.insert({a[u], u});
      }
    }
    return cnt;
  };

  while(boruvka());
  for(int i = 1; i <= n; i++){
    if(dsu.find(i) != dsu.find(1)){
      std::cout << "-1\n";
      return;
    }
  }

  std::cout << ans << "\n";
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