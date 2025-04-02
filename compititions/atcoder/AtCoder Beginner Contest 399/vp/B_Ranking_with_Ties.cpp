#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> b = a;
    std::sort(b.begin(),b.end(),std::greater<int>());

    for(int i = 0; i < n; ++i){
        std::cout << std::lower_bound(b.begin(),b.end(),a[i],std::greater<int>())-b.begin()+1 << "\n";
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