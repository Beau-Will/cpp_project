#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve(){
    int m;
    std::cin >> m;

    std::vector<int> v = {0,6,13,15,20};
    std::vector<int> dp(m+1,-inf);
    
    dp[0] = 0;
    for(int i = 1; i <= 4; ++i){
        for(int j = v[i]; j <= m; ++j){
            dp[j] = std::max(dp[j],dp[j-v[i]]+1);
        }
    }

    int sum = dp[m];
    for(int i = sum; i >= 0; --i){
        int rest1 = sum-i;
        for(int j = rest1; j >= 0; --j){
            int rest2 = rest1-j;
            for(int k = rest2; k >= 0; --k){
                int l = rest2-k;
                if(i*6+j*13+k*15+l*20==m){
                    std::cout << i << " " << j << " " << k << " " << l << "\n";
                    return;
                }
            }
        }
    }
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