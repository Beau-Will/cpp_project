#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector b(m,std::vector<std::string>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            std::cin >> b[i][j];
        }
    }

    for(int j = 0; j < n; ++j){
        bool isok = false;
        for(int i = 0; i < m; ++i){
            if(a[j]==b[i][j]){
                isok = true;
                break;
            }
        }
        if(!isok){
            std::cout << "-1\n";
            return;
        }
    }

    int res = 0;
    for(int i = 0; i < m; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            cnt += a[j]==b[i][j];
        }
        res = std::max(res,cnt);
    }

    int ans = n*3-res*2;

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