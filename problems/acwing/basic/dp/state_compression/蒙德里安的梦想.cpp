#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    while(std::cin >> n >> m){
        if(n==0&&m==0){
            break;
        }
        std::vector<bool> isok(1<<n);
        for(int i = 0; i < (1<<n); ++i){
            int cnt = 0;
            isok[i] = true;
            for(int j = 0; j < n; ++j){
                if(i>>j&1){
                    if(cnt&1){
                        isok[i] = false;
                    }
                    cnt = 0;
                }else{
                    ++cnt;
                }
            }
            if(cnt&1){
                isok[i] = false;
            }
        }

        std::vector dp(m+1,std::vector<i64>(1<<n));
        dp[0][0] = 1;
        for(int i = 1; i <= m; ++i){
            for(int j = 0; j < (1<<n); ++j){
                for(int k = 0; k < (1<<n); ++k){
                    if((j&k)==0&&isok[j|k]){
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }

        std::cout << dp[m][0] << "\n";
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