#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    int ans = n/100;
    n-=n/100*100;
    while(n>=20){
        ++ans;
        n-=20;
    }
    while(n>=10){
        ++ans;
        n-=10;
    }
    while(n>=5){
        ++ans;
        n-=5;
    }
    while(n>=1){
        ++ans;
        n-=1;
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