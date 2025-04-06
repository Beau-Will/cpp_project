#include <bits/stdc++.h>

using i64 = long long;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m;
    std::cin >> m;
    // std::vector<int> v(5);
    // v[1] = 6,v[2] = 13,v[3] = 15,v[4] = 20;

    // std::vector<int> dp(m+1);

    // for(int i = 1; i <= 4; ++i){
    //     for(int j = v[i]; j <= m; ++j){
    //         dp[j] = std::max(dp[j],dp[j-v[i]]+1);
    //     }
    // }
    // std::cout << dp[m] << "\n";

    // int sum = dp[m];

    for(int x1 = m/6; x1 >= 0; --x1){
        int rest1 = m-x1*6;
        for(int x2 = rest1/13; x2 >= 0; --x2){
            int rest2 = rest1-x2*13;
            for(int x3 = rest2/15; x3 >= 0; --x3){
                int rest3 = rest2-x3*15;
                if(rest3%20!=0){
                    continue;
                }
                int x4 = rest3/20;
                std::cout << x1 << " " << x2 << " " << x3 << " " << x4 << "\n";
                return 0;
            }
        }
    }

    return 0;
}