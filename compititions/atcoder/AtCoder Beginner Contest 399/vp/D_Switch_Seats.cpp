#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(2*n);
    for(int i = 0; i < 2*n; ++i){
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n+1);
    for(int i = 0; i < 2*n; ++i){
        adj[a[i]].push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < 2*n-1; ++i){
        if(a[i]!=a[i+1]){
            int pos1 = adj[a[i]].front(),pos2 = adj[a[i]].back();
            int pos3 = adj[a[i+1]].front(),pos4 = adj[a[i+1]].back();
            if(std::abs(pos1-pos2)==1){
                continue;
            }
            if(std::abs(pos3-pos4)==1){
                continue;
            }
            int t1 = pos1+pos2-i;
            int t2 = pos3+pos4-(i+1);
            if(std::abs(t1-t2)==1){
                ++ans;
            }
        }
    }

    std::cout << ans/2 << "\n";
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