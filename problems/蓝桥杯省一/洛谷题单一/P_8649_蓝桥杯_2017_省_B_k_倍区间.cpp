#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100000;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> cnt(N+1);
    cnt[0] = 1;

    int sum = 0;
    i64 ans = 0;
    for(int i = 1; i <= n; ++i){
        sum += a[i];
        sum %= k;
        ans += cnt[sum];
        ++cnt[sum];
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