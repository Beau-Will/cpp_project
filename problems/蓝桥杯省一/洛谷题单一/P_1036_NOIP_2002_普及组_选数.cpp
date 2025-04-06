#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::multiset<int> set;

    for(int i = 0; i < (1<<n); ++i){
        if(__builtin_popcount(i)!=k){
            continue;
        }
        int sum = 0;
        for(int j = 0; j < n; ++j){
            if(i>>j&1){
                sum += a[j];
            }
        }
        set.insert(sum);
    }

    auto isprime = [&](int x){
        if(x<2){
            return false;
        }
        for(int i = 2; i <= x/i; ++i){
            if(x%i==0){
                return false;
            }
        }
        return true;
    };
    
    int ans = 0;
    for(auto &ele:set){
        if(isprime(ele)){
            ++ans;
        }
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