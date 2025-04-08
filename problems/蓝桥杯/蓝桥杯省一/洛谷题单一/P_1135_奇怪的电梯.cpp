#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve(){
    int n,a,b;
    std::cin >> n >> a >> b;

    std::vector<int> k(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> k[i];
    }

    std::vector<bool> vis(n+1);
    std::vector<int> dist(n+1,inf);
    auto bfs = [&](int s,int t){
        std::queue<int> q;
        q.push(s);
        vis[s] = true;
        dist[s] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int u = t+k[t];
            if(u>=1&&u<=n&&!vis[u]){
                dist[u] = dist[t]+1;
                vis[u] = true;
                q.push(u);
            }
            int v = t-k[t];
            if(v>=1&&v<=n&&!vis[v]){
                dist[v] = dist[t]+1;
                vis[v] = true;
                q.push(v);
            }
        }
    };

    bfs(a,b);

    std::cout << (dist[b]==inf?-1:dist[b]) << "\n";
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