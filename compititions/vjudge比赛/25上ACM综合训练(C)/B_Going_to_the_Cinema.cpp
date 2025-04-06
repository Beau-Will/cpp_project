#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1000000000;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::sort(a.begin()+1,a.end());

    std::vector<int> pre(n+1),suf(n+2);
    pre[0] = -inf;
    for(int i = 1; i <= n; ++i){
        pre[i] = std::max(pre[i-1],a[i]);
    }
    suf[n+1] = inf;
    for(int i = n; i >= 1; --i){
        suf[i] = std::min(suf[i+1],a[i]);
    }

    std::vector<int> id(n+1);
    std::iota(id.begin(),id.end(),0);

    int ans = 0;
    for(int i = 0; i <= n; ++i){
        if(pre[i] < id[i] && suf[i+1] > id[i]){
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
    std::cin >> t;
    while(t--){
        solve();
    }

    return 0;
}