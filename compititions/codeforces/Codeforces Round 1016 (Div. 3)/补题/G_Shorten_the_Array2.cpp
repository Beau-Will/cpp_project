#include <bits/stdc++.h>

using i64 = long long;

template<typename T = i64,bool is_i64 = true>
struct xor_trie{
    std::vector<std::vector<int>> trie;
    std::vector<int> cnt;
    int len,idx;
    xor_trie(int n = 200000){
        len = is_i64?62:30;
        idx = 1;
        trie.assign((len+2)*n,std::vector<int>(2,0));
        cnt.assign((len+2)*n,0);
    }
    template<typename Q>
    void insert(T x,Q t){
        int p = 1;
        for(int i = len; i >= 0; --i){
            int &q = trie[p][x>>i&1];
            if(!q){
                q = ++idx;
            }
            p = q;
            cnt[p] += t;
        }
    }
    T query(T x){
        T res {};
        int p = 1;
        for(int i = len; i >= 0; --i){
            int t = x>>i&1;
            if(cnt[trie[p][t^1]]){
                t ^= 1;
                res |= 1LL<<i;
            }
            p = trie[p][t];
        }
        return res;
    }
};

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    xor_trie<int,false> trie(n);
    int ans = n+1;
    for(int i = 0,j = 0; j < n; ++j){
        trie.insert(a[j],1);
        while(i<=j&&trie.query(a[j])>=k){
            ans = std::min(ans,j-i+1);
            trie.insert(a[i],-1);
            ++i;
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