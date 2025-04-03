#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector<int> q(n+1);
    q[0] = -(inf+1);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int idx = std::lower_bound(q.begin(),q.begin()+ans+1,a[i])-q.begin()-1;
        ans = std::max(ans,idx+1);
        q[idx+1] = a[i];
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