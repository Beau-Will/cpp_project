#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::string a,b;
    std::cin >> n >> a >> m >> b;

    a = " "+a;
    b = " "+b;

    std::vector dp(n+1,std::vector<int>(m+1));
    for(int i = 0; i <= m; ++i){
        dp[0][i] = i;
    }
    for(int i = 0; i <= n; ++i){
        dp[i][0] = i;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
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