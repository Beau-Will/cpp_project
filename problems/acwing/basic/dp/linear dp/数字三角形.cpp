#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int n;
    std::cin >> n;

    std::vector dp(n+1,std::vector<int>(1,-inf));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            int x;
            std::cin >> x; 
            dp[i].push_back(x);
        }
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if(j == 1){
                dp[i][j] += dp[i-1][j];
            }else if(j == i){
                dp[i][j] += dp[i-1][j-1];
            }else{
                dp[i][j] += std::max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    std::cout << *std::max_element(dp[n].begin()+1,dp[n].end()) << "\n";
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