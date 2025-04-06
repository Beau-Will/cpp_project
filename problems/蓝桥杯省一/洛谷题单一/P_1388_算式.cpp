#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::vector dp(n+5,std::vector(n+5,std::vector<i64>(n+5)));

    dp[1][1][0] = a[1];
    for(int i = 2; i <= n; ++i){
        dp[1][i][i-1] = dp[1][i-1][i-2]*a[i];
    }
    for(int i = 2; i <= n; ++i){
        dp[1][i][0] = dp[1][i-1][0]+a[i];
    }
    for(int i = 1; i <= n; ++i){
        dp[i][i][0] = a[i];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            for(int k = 0; k <= j-i && k <= m; ++k){
                for(int l = i; l <= j; ++l){
                    if(l-i>=k-1){
                        dp[i][j][k] = std::max(dp[i][j][k],dp[i][l][k-1]*(dp[1][j][0]-dp[1][l][0]));
                    }
                    if(j-l>=k-1){
                        dp[i][j][k] = std::max(dp[i][j][k],dp[l+1][j][k-1]*dp[1][l][0]);
                    }
                    if(a[j-1]==0&&a[j]==0&&j-2>=k-1){
                        dp[i][j][k] = std::max(dp[i][j][k],dp[i][j-2][k-1]);
                    }
                }
            }
        }
    }

    std::cout << dp[1][n][m] << "\n";
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