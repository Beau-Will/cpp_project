#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::vector dp(1001,std::vector<int>(1001));
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
        a[i] = " "+a[i];
    }

    while(m--){
        std::string b;
        int k;
        std::cin >> b >> k;
        b = " "+b;
        auto isok = [&](std::string &s,std::string &t){
            for(int i = 0; i < t.size(); ++i){
                dp[0][i] = i;
            }
            for(int i = 0; i < s.size(); ++i){
                dp[i][0] = i;
            }
            for(int i = 1; i < s.size(); ++i){
                for(int j = 1; j < t.size(); ++j){
                    if(s[i]==t[j]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                }
            }
            return dp[s.size()-1][t.size()-1] <= k;
        };
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(isok(a[i],b)){
                ++ans;
            }
        }
        std::cout << ans << "\n";
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