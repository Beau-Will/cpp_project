#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/**
 * Kosaraju算法求强连通分量和缩点 (1-based版本)
 *
 * @param n 节点数，节点编号为 1..n
 * @param edges 有向边列表，每条边为 (u, v)，u和v均为1-based，而edges下标0-based
 * @return 返回一个元组：
 *         1. scc_id: 每个节点所属的SCC编号（1-based）
 *         2. scc_count: 强连通分量总数
 *         3. scc_graph: 缩点后的DAG邻接表，下标1-based
 */
std::tuple<std::vector<int>, int, std::vector<std::vector<int>>> 
kosaraju_scc_1based(int n, const std::vector<std::pair<int, int>>& edges) {
  // 构建原图和反图
  std::vector<std::vector<int>> adj(n + 1), radj(n + 1);
  for (const auto& [u, v] : edges) {
    adj[u].push_back(v);
    radj[v].push_back(u);
  }

  std::vector<bool> vis(n + 1, false);
  std::vector<int> order; // 存储第一次DFS的后序遍历顺序

  // 第一次DFS：获取后序遍历顺序
  std::function<void(int)> dfs1 = [&](int u) {
    vis[u] = true;
    for (int v : adj[u]) {
      if (!vis[v]) {
        dfs1(v);
      }
    }
    order.push_back(u);
  };

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs1(i);
    }
  }

  // 第二次DFS：在反图上标记强连通分量
  std::vector<int> scc_id(n + 1, 0); // 0表示未访问
  int scc_count = 0;

  std::function<void(int, int)> dfs2 = [&](int u, int id) {
    scc_id[u] = id;
    for (int v : radj[u]) {
      if (scc_id[v] == 0) {
        dfs2(v, id);
      }
    }
  };

  // 按第一次DFS的逆序进行第二次DFS
  for (int i = n - 1; i >= 0; i--) {
    int u = order[i];
    if (scc_id[u] == 0) {
      dfs2(u, ++scc_count); // SCC编号从1开始
    }
  }

  // 构建缩点后的图
  std::vector<std::vector<int>> scc_adj(scc_count + 1); // 下标1-based

  for (const auto& [u, v] : edges) {
    int id_u = scc_id[u];
    int id_v = scc_id[v];
    if (id_u != id_v) {
      scc_adj[id_u].push_back(id_v);
    }
  }

  // 去重（可选）
  for (int i = 1; i <= scc_count; i++) {
    sort(scc_adj[i].begin(), scc_adj[i].end());
    scc_adj[i].erase(unique(scc_adj[i].begin(), scc_adj[i].end()), scc_adj[i].end());
  }

  return {scc_id, scc_count, scc_adj};
}

/**
 * 计算每个强连通分量的大小 (1-based版本)
 */
std::vector<int> scc_size_1based(const std::vector<int>& scc_id, int n, int scc_count) {
  std::vector<int> size(scc_count + 1, 0); // 下标1-based
  for (int i = 1; i <= n; i++) {
    size[scc_id[i]]++;
  }
  return size;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;
  
  std::vector<std::pair<int,int>> edges(m);
  for(int i = 0; i < m; i++){
    auto& [u, v] = edges[i];
    std::cin >> u >> v;
  }
  
  auto [scc_id, scc_cnt, scc_adj] = kosaraju_scc_1based(n, edges);
  auto scc_siz = scc_size_1based(scc_id, n, scc_cnt);

  std::vector<int> out(scc_cnt + 1);
  for(int i = 1; i <= scc_cnt; i++){
    out[i] = scc_adj[i].size();
  }

  std::vector<int> out0;
  for(int i = 1; i <= scc_cnt; i++){
    if(out[i] == 0){
      out0.push_back(i);
    }
  }

  int ans = 0;
  if(out0.size() == 1){
    ans = scc_siz[out0.front()];
  }

  std::cout << ans << "\n";
}