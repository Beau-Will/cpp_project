#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> s(n),b(n);
    for(int i = 0; i < n; ++i){
        std::cin >> s[i] >> b[i];
    }

    int ans = 2*inf;
    for(int i = 0; i < (1<<n); ++i){
        if(__builtin_popcount(i)==0){
            continue;
        }
        int mul = 1,sum = 0;
        for(int j = 0; j < n; ++j){
            if(i>>j&1){
                mul *= s[j];
                sum += b[j];
            }
        }
        ans = std::min(ans,std::abs(mul-sum));
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