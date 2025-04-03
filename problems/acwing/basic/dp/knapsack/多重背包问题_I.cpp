#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<int> v(n+1),w(n+1),s(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> v[i] >> w[i] >> s[i];
    }

    std::vector dp(n+1,std::vector<int>(m+1));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            for(int k = 0; k <= s[i] && k*v[i] <= j; ++k){
                if(k == 0){
                    dp[i][j] = std::max(dp[i][j],dp[i-1][j]);
                }else{
                    dp[i][j] = std::max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
                }
            }
        }
    }

    std::cout << dp[n][m] << "\n";
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