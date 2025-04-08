#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve(){
    int x,k;
    std::cin >> x >> k;

    int len = std::to_string(x).size();
    i64 base = std::pow(10,len);

    i64 t = 0;
    while(t<=inf&&k){
        t = t*base+x;
        --k;
    }

    auto is_prime = [&](i64 x){
        if(x<2){
            return false;
        }
        for(i64 i = 2; i <= x/i; ++i){
            if(x%i==0){
                return false;
            }
        }
        return true;
    };

    if(is_prime(t)){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
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