#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<int> v(n+1),w(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> v[i] >> w[i];
    }

    std::vector<int> dp(m+1);
    for(int i = 1; i <= n; ++i){
        for(int j = v[i]; j <= m; ++j){
            dp[j] = std::max(dp[j],dp[j-v[i]]+w[i]);
        }
    }

    std::cout << dp[m] << "\n";
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