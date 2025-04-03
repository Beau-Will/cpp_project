#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 1'000'000'007;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            dp[j] = (dp[j]+dp[j-i])%P;
        }
    }
    std::cout << dp[n] << "\n";
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