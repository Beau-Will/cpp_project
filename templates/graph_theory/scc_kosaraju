std::vector<std::vector<int>> edges; // 原有向图
std::vector<std::vector<int>> rev_edges; // 反向图
std::vector<bool> vis;
std::stack<int> s;

void dfs1(int u) {
    vis[u] = true;
    for (auto v : edges[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    s.push(u);
}

void dfs2(int u, std::vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (auto v : rev_edges[u]) {
        if (!vis[v]) {
            dfs2(v, component);
        }
    }
}

std::vector<std::vector<int>> kosaraju() {
    int n = edges.size();
    vis.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    vis.assign(n, false);
    std::vector<std::vector<int>> components;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!vis[u]) {
            std::vector<int> component;
            dfs2(u, component);
            components.push_back(component);
        }
    }
    return components;
}