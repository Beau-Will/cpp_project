#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector v(n+1,std::vector<int>(1)),w(n+1,std::vector<int>(1));
    std::vector<int> s(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> s[i];
        for(int j = 1; j <= s[i]; ++j){
            int x,y;
            std::cin >> x >> y;
            v[i].push_back(x);
            w[i].push_back(y);
        }
    }

    std::vector<int> dp(m+1);
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 0; --j){
            for(int k = 1; k <= s[i]; ++k){
                if(j<v[i][k]){
                    continue;
                }
                dp[j] = std::max(dp[j],dp[j-v[i][k]]+w[i][k]);
            }
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