#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> pre(n+1);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1]+a[i];
    }

    std::vector dp(n+1,std::vector<int>(n+1,inf));
    for(int i = 1; i <= n; ++i){
        dp[i][i] = 0;
    }
    for(int ran = 2; ran <= n; ++ran){
        for(int i = 1; i+ran-1 <= n; ++i){
            int l = i,r = i+ran-1;
            for(int j = l; j < r; ++j){
                dp[l][r] = std::min(dp[l][r],dp[l][j]+dp[j+1][r]+pre[r]-pre[l-1]);
            }
        }
    }

    std::cout << dp[1][n] << "\n";
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