#include <bits/stdc++.h>

using i64 = long long;

using Edge = int;
struct HLD{
    int n;
    std::vector<int> sz, top, dep, fa, in, out, seq;
    std::vector<std::vector<Edge> > g;
    int ts;
 
    HLD(const std::vector<std::vector<Edge>> &g,int root = 1):n(int(g.size())-1),g(g){
        ts = 0;
        sz.resize(n + 1);
        top.resize(n + 1);
        dep.resize(n + 1);
        fa.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);
        seq.resize(n + 1);
        dep[root] = 1;
        top[root] = root;
        dfs_sz(root);
        dfs_hld(root);
    }
 
    void dfs_sz(int u){
        if (fa[u]){
            for(auto it = g[u].begin(); it != g[u].end(); it++){
                if (*it == fa[u]){
                    g[u].erase(it);
                    break;
                }
            }
        }
        sz[u] = 1;
        for(auto &j : g[u]){
            fa[j] = u;
            dep[j] = dep[u] + 1;
            dfs_sz(j);
            sz[u] += sz[j];
            if (sz[j] > sz[g[u][0]])
                std::swap(j, g[u][0]);
        }
    }
 
    void dfs_hld(int u){
        in[u] = ++ts;
        seq[in[u]] = u;
        for (auto j : g[u]){
            top[j] = (j == g[u][0] ? top[u] : j);
            dfs_hld(j);
        }
        out[u] = ts;
    }
 
    int lca(int u, int v){
        while (top[u] != top[v]){
            if (dep[top[u]] > dep[top[v]]){
                u = fa[top[u]];
            } 
            else{
                v = fa[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
 
    int dist(int u, int v){
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
 
    bool in_subtree(int u, int v){
        return in[v] <= in[u] && in[u] <= out[v];
    }
     
    int jump(int u, int k) {
        if (dep[u] < k){
            return -1;
        }
        int d = dep[u] - k;
        while (dep[top[u]] > d){
            u = fa[top[u]];
        }
        return seq[in[u] - dep[u] + d];
    }
     
    int rooted_lca(int a, int b, int c){
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
 
    template<typename Q>
    void modify_path(int u, int v, const Q &q, bool edge = false){
        while(top[u] != top[v]){
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
            q(in[top[u]], in[u]);
            u = fa[top[u]];        
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        q(in[u] + edge, in[v]);
    }
 
    template<typename Q>
    void modify_subtree(int u, const Q &q){
        q(in[u], out[u]);
    }  
 
    template<typename T, typename Q>
    T query_path(int u, int v, const Q &q, bool edge = false){
        T ret = T();
        while(top[u] != top[v]){
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
            ret = q(in[top[u]], in[u]) + ret;
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v);
        return q(in[u] + edge, in[v]) + ret;
    }
 
    template<typename T, typename Q>
    T query_subtree(int u, const Q &q){
        return q(in[u], out[u]);
    }
 
    template<typename T, typename Q, typename F>
    T query_path_noncommutative(int u, int v, const Q &q, const F &f, bool edge = false){
        T left = T(), right = T();
        while(top[u] != top[v]){
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v), std::swap(left, right);
            left = q(in[top[u]], in[u]) + left;
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) std::swap(u, v), std::swap(left, right);
        return f(left, q(in[u] + edge, in[v]) + right);
    }
     
    std::pair<std::vector<int>, std::vector<std::pair<int, int>>> compress(std::vector<int> v){
        auto cmp = [&](int a, int b) { return in[a] < in[b]; };
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        const int k = (int)v.size();
        for(int i = 0; i + 1 < k; i++){
            v.push_back(lca(v[i], v[i + 1]));
        }
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        std::vector<std::pair<int, int> > edges;
        std::vector<int> stk;
        for(auto x : v){
            while(!stk.empty() && out[stk.back()] < in[x]){
                stk.pop_back();
            }
            if (!stk.empty()){
                edges.push_back({stk.back(), x});
            }
            stk.push_back(x);
        }
        return {v, edges};
    }
};