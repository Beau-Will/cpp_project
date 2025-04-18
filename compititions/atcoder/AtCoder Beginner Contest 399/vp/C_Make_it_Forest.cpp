#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    int _n;
    std::vector<int> _fa,_size;
    DSU(){}
    DSU(int n){
        init(n);
    }
    void init(int n) {
        _fa.resize(n);
        std::iota(_fa.begin(),_fa.end(),0);
        _size.assign(n,1);
    }
    int find(int x) {
        if(x!=_fa[x]) {
            _fa[x] = find(_fa[x]);
        }
        return _fa[x];
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
    bool merge(int x,int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx!=fy) {
            _size[fx]+=_size[fy];
            _fa[fy] = fx;
            return true;
        }
        return false;
    }
};

void solve(){
    int n,m;
    std::cin >> n >> m;

    DSU dsu(n);
    for(int i = 0; i < m; ++i){
        int u,v;
        std::cin >> u >> v;
        --u,--v;
        dsu.merge(u,v);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(dsu.find(i)==i){
            ++ans;
        }
    }

    std::cout << ans+m-n << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}