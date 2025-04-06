#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> dp(31);
    for(int i = 1; i <= n; ++i){
        int max = 0;
        for(int j = 0; j < 31; ++j){
            if(a[i]>>j&1){
                max = std::max(max,dp[j]+1);
            }
        }
        for(int j = 0; j < 31; ++j){
            if(a[i]>>j&1){
                dp[j] = std::max(dp[j],max);
            }
        }
    }

    std::cout << *std::max_element(dp.begin(),dp.end()) << "\n";
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