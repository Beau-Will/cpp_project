#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for(int i = 0; i < n; ++i){
        std::cin >> h[i];
    }

    std::vector<std::vector<int>> adj(n);
    std::vector<int> fa(n,-1);
    for(int i = 0; i < n-1; ++i){
        int u,v;
        std::cin >> u >> v;
        --u,--v;
        adj[v].push_back(u);
        fa[u] = v;
    }

    int rt = 0;
    while(fa[rt]!=-1){
        ++rt;
    }

    std::vector dp(n,std::vector<int>(2));

    auto dfs = [&](auto &&self,int u)->void{
        dp[u][1] = h[u];
        for(auto &v:adj[u]){
            self(self,v);
            dp[u][1] += dp[v][0];
            dp[u][0] += std::max(dp[v][0],dp[v][1]);
        }
    };

    dfs(dfs,rt);

    std::cout << std::max(dp[rt][0],dp[rt][1]) << "\n";
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