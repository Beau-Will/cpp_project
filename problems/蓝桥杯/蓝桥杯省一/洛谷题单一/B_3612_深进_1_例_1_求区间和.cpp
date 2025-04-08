#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n+1);

    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }
    
    std::vector<int> pre(n+1);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1]+a[i];
    }

    int m;
    std::cin >> m;
    while(m--){
        int l,r;
        std::cin >> l >> r;

        std::cout << pre[r]-pre[l-1] << "\n";
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