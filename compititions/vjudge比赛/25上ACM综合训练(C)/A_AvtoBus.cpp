#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    i64 n;
    std::cin >> n;
    if((n&1) || n < 4){
        std::cout << "-1\n";
        return;
    }

    std::cout << (n%6==0?n/6:n/6+1) << " " << n/4 << "\n";
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