#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<int> v(1),w(1);
    for(int i = 1; i <= n; ++i){
        int x,y,z;
        std::cin >> x >> y >> z;
        int t = 1;
        while(t<=z){
            v.push_back(t*x);
            w.push_back(t*y);
            z-=t;
            t*=2;
        }
        if(z){
            v.push_back(z*x);
            w.push_back(z*y);
            z = 0;
        }
    }

    std::vector<int> dp(m+1);
    for(int i = 1; i < v.size(); ++i){
        for(int j = m; j >= v[i]; --j){
            dp[j] = std::max(dp[j],dp[j-v[i]]+w[i]);
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