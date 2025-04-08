#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 32*200000;

int tot;
 
int trie[N][2];
int cnt[N];
 
int newNode() {
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}
 
void init() {
    tot = 0;
    newNode();
}
 
void add(int x, int t) {
    int o = 1;
    for (int i = 29; i >= 0; i--) {
        int &p = trie[o][x >> i & 1];
        if (!p) {
            p = newNode();
        }
        o = p;
        cnt[o] += t;
    }
}
 
int query(int x) {
    int o = 1;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int d = x >> i & 1;
        if (cnt[trie[o][d ^ 1]]) {
            d ^= 1;
            ans |= 1 << i;
        }
        o = trie[o][d];
    }
    return ans;
}

void solve(){
    int n,k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    auto check = [&](int len){
        init();
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            add(a[i],1);
            ++cnt;
            if(cnt==len+1){
                add(a[i-len],-1);
                --cnt;
            }
            if(query(a[i])>=k){
                return true;
            }
        }
        return false;
    };

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