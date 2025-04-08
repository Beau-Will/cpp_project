#include <bits/stdc++.h>

using i64 = long long;

int n,k,idx;
int trie[32*200001][2],cnt[32*200001],a[200001];

int new_node(){
    int x = ++idx;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void init(){
    idx = 0;
    new_node();
}

void insert(int x,int t){
    int p = 1;
    for(int i = 30; i >= 0; --i){
        int &q = trie[p][x>>i&1];
        if(!q){
            q = new_node();
        }
        p = q;
        cnt[p] += t;
    }
}

int query(int x){
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
}

bool check(int len){
    init();
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        insert(a[i],1);
        ++cnt;
        if(cnt==len+1){
            insert(a[i-len],-1);
            --cnt;
        }
        if(query(a[i])>=k){
            return true;
        }
    }
    return false;
}

void solve(){
    std::cin >> n >> k;
    
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    int lo = 1,hi = n+1;
    while(lo < hi){
        int mid = (lo+hi)>>1;
        if(check(mid)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    std::cout << (lo==n+1?-1:lo) << "\n";
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