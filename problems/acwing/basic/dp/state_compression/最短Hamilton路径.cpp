#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int n;
    std::cin >> n;

    std::vector dist(n,std::vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            std::cin >> dist[i][j];
        }
    }

    std::vector dp(1<<n,std::vector<int>(n,2*inf));
    dp[1][0] = 0;
    for(int i = 0; i < (1<<n); ++i){
        for(int j = 0; j < n; ++j){
            if(i>>j&1){
                for(int k = 0; k < n; ++k){
                    if(i>>k&1){
                        dp[i][j] = std::min(dp[i][j],dp[i-(1<<j)][k]+dist[k][j]);
                    }
                }
            }
        }
    }

    std::cout << dp[(1<<n)-1][n-1] << "\n";
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