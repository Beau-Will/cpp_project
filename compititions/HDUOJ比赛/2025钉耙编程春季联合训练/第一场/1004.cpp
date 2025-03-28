#include<bits/stdc++.h>

using namespace std;
using i128 = __int128;
using u64 = unsigned long long;


#define cc(x) cout << fixed << setprecision(x)
#define int long long

const int N = 2e5 + 10;


const int inf = 1e18, mod = 1e9 + 7;


struct RMQ {
    vector<vector<int>>st;
    vector<int>LOG;
    int n;
    int get(int x, int y){
        return max(x, y);
    }
    RMQ(const vector<int>& a) {
        this->n = (int)a.size() - 1;
        LOG.resize(n + 1);
        for (int i = 2; i <= n; i++)LOG[i] = LOG[i / 2] + 1;
 
        st.resize(n + 1, vector<int>(LOG[n] + 1));
        for (int i = 1; i <= n; i++)st[i][0] = a[i];
        for (int j = 1; 1 << j <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = get(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
            }
        }
    }
 
    int operator() (int L, int R) {
        int j = LOG[R - L + 1];
        return get(st[L][j], st[R - (1 << j) + 1][j]);
    }
};


void solve() {

    int n, q;
    cin >> n >> q;
   
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    set<pair<int, int>> st;
    
    vector<int> pre(n + 1);

    if(n == 1) st.insert({1, 1}), pre[1] = 1;
    else if(n == 2) {
        st.insert({1, 2});
        pre[1] = 2;
    }
    else {
        int l = min(a[1], a[2]), r = max(a[1], a[2]);
        int lst = 1;

        for (int i = 3; i <= n + 1; i ++) {
            if(i == n + 1) {
                st.insert({lst, i - 1});
                pre[lst] = i - lst;

                break;
            }
            l = max(l, min(a[i - 1], a[i])), r = min(r, max(a[i - 1], a[i]));
            if(l >= r) {
                st.insert({lst, i - 1});
                pre[lst] = i - lst;
                l = min(a[i], a[i - 1]), r = max(a[i], a[i - 1]);
                lst = i - 1;
            }
        }

    }
    st.insert({inf, inf});
    st.insert({-inf, -inf});

    RMQ ST(pre);

    int ans = 0;
    for (int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        int lst = x;

        auto it = st.lower_bound({lst, -inf});
        while(it->second > x) {
            --it;
        }
        while(it->second < x) {
            it ++;
        }
        int res = 1;
        //
        res = max(res,min(y, it->second) - max(x, it->first) + 1);
        ++it;
        int L = inf, R = -inf;
        if(it->first < inf) L = it->first;
        auto itr = st.lower_bound({y, -inf});
        while(itr->first > y) itr --;

        res = max(res, min(y, itr->second) - max(x, itr->first) + 1);
        itr --;
        if(itr->first > -inf) R = itr->first;
        if(L <= R) {
            res = max(res, ST(L, R));
        } 
        ans = (ans + res * i % mod) % mod;
    }
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}