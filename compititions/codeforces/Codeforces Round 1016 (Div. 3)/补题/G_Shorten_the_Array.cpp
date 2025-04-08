#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::vector trie(32*(n+1),std::vector<int>(2));
    std::vector<int> cnt(32*(n+1));
    int idx = 1;

    auto insert = [&](int x,int t){
        int p = 1;
        for(int i = 30; i >= 0; --i){
            int &q = trie[p][x>>i&1];
            if(!q){
                q = ++idx;
            }
            p = q;
            cnt[p] += t;
        }
    };

    auto query = [&](int x){
        int res = 0,p = 1;
        for(int i = 30; i >= 0; --i){
            int t = x>>i&1;
            if(cnt[trie[p][t^1]]){
                t ^= 1;
                res |= 1<<i;
            }
            p = trie[p][t];
        }
        return res;
    };

    int ans = n+1;
    for(int i = 0,j = 0; i < n; ++i){
        insert(a[i],1);
        while(j<=i&&query(a[i])>=k){
            ans = std::min(ans,i-j+1);
            insert(a[j],-1);
            ++j;
        }
    }

    std::cout << (ans>n?-1:ans) << "\n";
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