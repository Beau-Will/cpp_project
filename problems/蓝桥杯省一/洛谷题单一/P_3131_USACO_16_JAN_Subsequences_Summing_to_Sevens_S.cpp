#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::map<int,std::vector<int>> cnt;
    cnt[0].push_back(0);
    int sum = 0,ans = 0;
    for(int i = 1; i <= n; ++i){
        sum += a[i];
        sum %= 7;
        if(cnt[sum].size()){
            ans = std::max(ans,i-cnt[sum].front());
        }
        cnt[sum].push_back(i);
    }

    std::cout << ans << "\n";
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