#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int,int>>> adj(n);
    for(int i = 0; i < n-1; ++i){
        int u,v,w;
        std::cin >> u >> v >> w;
        --u,--v,w = w&1;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    std::vector<bool> vis(n);
    std::vector<int> color(n);

    auto bfs = [&](){
        std::queue<int> q;
        vis[0] = true;
        color[0] = 0;
        q.push(0);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto &[v,w]:adj[u]){
                if(vis[v]){
                    continue;
                }
                vis[v] = true;
                color[v] = color[u]^w;
                q.push(v);
            }
        }
    };

    bfs();

    i64 cnt0 = 0,cnt1 = 0;
    for(int i = 0; i < n; ++i){
        if(color[i]){
            ++cnt1;
        }else{
            ++cnt0;
        }
    }

    i64 ans = cnt0*cnt0*cnt0+cnt1*cnt1*cnt1;

    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}