#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int k;
    std::cin >> k;

    std::cout << (k&1?"YES\n":"NO\n");
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