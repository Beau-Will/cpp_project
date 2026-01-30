#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

/**   树链剖分（HLD）
 *    2023-08-31: https://codeforces.com/contest/1863/submission/221214363
**/
struct HLD {
  int n;
  std::vector<int> siz, top, dep, parent, in, out, seq;
  std::vector<std::vector<int>> adj;
  int cur;

  HLD() {}
  HLD(int n) {
    init(n);
  }
  void init(int n) {
    this->n = n;
    siz.resize(n);
    top.resize(n);
    dep.resize(n);
    parent.resize(n);
    in.resize(n);
    out.resize(n);
    seq.resize(n);
    cur = 0;
    adj.assign(n, {});
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void work(int root = 0) {
    top[root] = root;
    dep[root] = 0;
    parent[root] = -1;
    dfs1(root);
    dfs2(root);
  }
  void dfs1(int u) {
    if (parent[u] != -1) {
      adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }

    siz[u] = 1;
    for (auto& v : adj[u]) {
      parent[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[adj[u][0]]) {
        std::swap(v, adj[u][0]);
      }
    }
  }
  void dfs2(int u) {
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto v : adj[u]) {
      top[v] = v == adj[u][0] ? top[u] : v;
      dfs2(v);
    }
    out[u] = cur;
  }
  int lca(int u, int v) {
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        u = parent[top[u]];
      } else {
        v = parent[top[v]];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

  int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int jump(int u, int k) {
    if (dep[u] < k) {
      return -1;
    }

    int d = dep[u] - k;

    while (dep[top[u]] > d) {
      u = parent[top[u]];
    }

    return seq[in[u] - dep[u] + d];
  }

  bool isAncester(int u, int v) {
    return in[u] <= in[v] && in[v] < out[u];
  }

  int rootedParent(int u, int v) {
    std::swap(u, v);
    if (u == v) {
      return u;
    }
    if (!isAncester(u, v)) {
      return parent[u];
    }
    auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
      return in[x] < in[y];
    }) - 1;
    return *it;
  }

  int rootedSize(int u, int v) {
    if (u == v) {
      return n;
    }
    if (!isAncester(v, u)) {
      return siz[v];
    }
    return n - siz[rootedParent(u, v)];
  }

  int rootedLca(int a, int b, int c) {
    return lca(a, b) ^ lca(b, c) ^ lca(c, a);
  }
};


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n;
  std::cin >> n;
  
  std::vector p(n, std::array<int,2>{});
  std::vector<int> all;
  int rt;
  for(int i = 0; i < n; i++){
    int u,v;
    std::cin >> u >> v;
    p[i] = {u, v};
    if(v == -1){
      rt = u;
      all.push_back(u);
      continue;
    }
    all.push_back(u);
    all.push_back(v);
  }
  
  std::sort(all.begin(), all.end());
  all.erase(std::unique(all.begin(), all.end()), all.end());
  
  auto query = [&](int x){
    return std::lower_bound(all.begin(), all.end(), x) - all.begin();
  };
  
  HLD hld(n);
  
  for(int i = 0; i < n; i++){
    auto [u, v] = p[i];
    if(v == -1){
      continue;
    }
    
    int idxu = query(u);
    int idxv = query(v);
    hld.addEdge(idxu, idxv);
  }
  
  rt = query(rt);
  
  hld.work(rt);
  
  int m;
  std::cin >> m;
  
  for(int mi = 0; mi < m; mi++){
    int u,v;
    std::cin >> u >> v;
    
    int idxu = query(u);
    int idxv = query(v);
    
    int uvlca = hld.lca(idxu, idxv);
    if(idxu == uvlca){
      std::cout << "1\n";
    }else if(idxv == uvlca){
      std::cout << "2\n";
    }else{
      std::cout << "0\n";
    }
  }
}