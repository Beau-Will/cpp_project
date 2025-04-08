#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    auto check = [&](int x){
        std::vector<bool> vis(n);
        int res = 0,cnt = 0;// < x
        for(int i = 0; i < n; ++i){
            if(a[i]>=x){
                continue;
            }
            if(!vis[a[i]]){
                vis[a[i]] = true;
                ++cnt;
            }
            if(cnt==x){
                cnt = 0;
                ++res;
                std::fill(vis.begin(),vis.end(),false);
            }
        }
        return res >= k;
    };

    int lo = 0,hi = n;
    while(lo < hi){
        int mid = (lo+hi+1)>>1;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }

    std::cout << lo << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}