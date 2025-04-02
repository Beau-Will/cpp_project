#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::string s,t;
    std::cin >> s >> t;

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i]!=t[i]){
            ++cnt;
        }
    }

    std::cout << cnt << "\n";
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