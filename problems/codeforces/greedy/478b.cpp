#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    i64 n,m;
    std::cin >> n >> m;
    /*
    min:[n/m,n/m,n/m+1,...,n/m+1]
    max:[1,1,1,...,n-m+1]
    */
    i64 d = n/m, r = n%m;

    std::cout << (m-r)*(d*(d-1)/2)+r*((d+1)*d/2) << " ";
    std::cout << ((n-m+1)*(n-m)/2) << "\n";
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