#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<std::string> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> dp(10);
    for(int i = 1; i <= n; ++i){
        int l = a[i][0]-'0';
        int r = a[i][a[i].size()-1]-'0';
        dp[r] = std::max(dp[r],dp[l]+1);
    }

    int max = 0;
    for(int i = 0; i < 10; ++i){
        max = std::max(max,dp[i]);
    }

    std::cout << n-max << "\n";
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