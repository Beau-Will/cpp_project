#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <array>

/**
 * 树链剖分（HLD）模板
 * 支持边权查询和LCA计算
 * 使用1-indexed节点编号
 */
template<typename T = int>
struct HLD {
  int n;
  std::vector<int> siz, top, dep, parent, in, out, seq;
  std::vector<std::vector<std::pair<int, T>>> adj;  // 邻接表，存储(邻居, 边权)
  std::vector<T> dist;  // 节点到根的距离
  int cur;

  HLD() {}
  HLD(int n) {
    init(n);
  }

  void init(int n) {
    this->n = n;
    siz.resize(n + 1);
    top.resize(n + 1);
    dep.resize(n + 1);
    parent.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    seq.resize(n + 1);
    dist.resize(n + 1);
    cur = 0;
    adj.assign(n + 1, {});
  }

  // 添加带权边
  void addEdge(int u, int v, T w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  void work(int root = 1) {
    top[root] = root;
    dep[root] = 0;
    dist[root] = 0;
    parent[root] = -1;
    dfs1(root);
    dfs2(root);
  }

  void dfs1(int u) {
    siz[u] = 1;
    // 移除父节点
    for (auto it = adj[u].begin(); it != adj[u].end();) {
      int v = it->first;
      if (v == parent[u]) {
        it = adj[u].erase(it);
      } else {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dist[v] = dist[u] + it->second;  // 更新距离
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[adj[u][0].first]) {
          std::swap(*it, adj[u][0]);
        }
        ++it;
      }
    }
  }

  void dfs2(int u) {
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto& p : adj[u]) {
      int v = p.first;
      top[v] = (v == adj[u][0].first) ? top[u] : v;
      dfs2(v);
    }
    out[u] = cur;
  }

  // 求LCA
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

  // 求两点间距离（基于边权）
  T distance(int u, int v) {
    int p = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[p];
  }

  // 求深度距离（节点数）
  int depthDist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  // 向上跳k步
  int jump(int u, int k) {
    if (dep[u] < k) return -1;
    int d = dep[u] - k;
    while (dep[top[u]] > d) {
      u = parent[top[u]];
    }
    return seq[in[u] - dep[u] + d];
  }

  // 判断u是否是v的祖先
  bool isAncestor(int u, int v) {
    return in[u] <= in[v] && in[v] < out[u];
  }

  // 获取路径上的边权和（如果需要的话）
  T pathSum(int u, int v) {
    T res = 0;
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
      // 这里可以处理路径上的信息，比如区间查询
      u = parent[top[u]];
    }
    if (dep[u] > dep[v]) std::swap(u, v);
    // 处理重链上的信息
    return res;
  }
};

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  
  HLD hld(n);
  for(int i = 0; i < n - 1; i++){
    int u, v, w;
    std::cin >> u >> v >> w;
    
    hld.addEdge(u, v, w);
  }
  
  hld.work();
  
  for(int mi = 0; mi < m; mi++){
    int u, v;
    std::cin >> u >> v;
    
    std::cout << hld.distance(u, v) << "\n";
  }
}