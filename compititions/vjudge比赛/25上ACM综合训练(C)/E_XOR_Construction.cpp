#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for(int i = 1; i < n; ++i){
        std::cin >> b[i];
    }

    std::vector<int> pre(n);
    for(int i = 1; i < n; ++i){
        pre[i] = pre[i-1]^b[i];
    }

    std::vector<int> cnt(31);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 31; ++j){
            if(i>>j&1){
                ++cnt[j];
            }
        }
    }

    int a0 = 0;
    for(int i = 0; i < 31; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            int aj = a0^pre[j];
            if(aj>>i&1){
                ++sum;
            }
        }
        if(sum!=cnt[i]){
            a0 |= 1<<i;
        }
    }

    for(int i = 0; i < n; ++i){
        std::cout << (a0^pre[i]) << " \n"[i+1==n];
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