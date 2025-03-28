#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    for(int i = 2; i <= n/i; ++i){
        if(n%i==0){
            int x = n/i;
            for(int j = 2; j <= x/j; ++j){
                if(j==i){
                    continue;
                }
                if(x%j==0){
                    if(x/j==i || j==x/j){
                        continue;
                    }
                    std::cout << "YES\n";
                    std::cout << i << " " << j << " " << x/j << "\n";
                    return;
                }
            }
        }
    }

    std::cout << "NO\n";
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