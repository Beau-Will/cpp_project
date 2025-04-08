#include <bits/stdc++.h>

using i64 = long long;

template<typename T = i64,bool is_i64 = true>
struct linear_basis{
    std::vector<T> d;
    int len;
    linear_basis(){
        d.assign(is_i64?64:32,T{});
        len = is_i64?62:30;
    }
    template<typename Q>
    void insert(Q x){
        for(int i = len; i >= 0; --i){
            if(x&(1LL<<i)){
                if(d[i]){
                    x ^= d[i];
                }else{
                    d[i] = x;
                    break;
                }
            }
        }
    }
    T find_max(){
        T res {};
        for(int i = len; i >= 0; --i){
            if(res^d[i]>res){
                res ^= d[i];
            }
        }
        return res;
    }
    int count(){
        int res = 0;
        for(int i = len; i >= 0; --i){
            if(d[i]){
                ++res;
            }
        }
        return res;
    }
};

void solve(){
    int n,m;
    std::cin >> n >> m;
    std::vector<std::string> s(m);
    for(int i = 0; i < m; ++i){
        std::cin >> s[i];
    }

    std::vector<i64> a(m);
    for(int i = 0; i < m; ++i){
        i64 x = 0;
        for(int j = 0; j < n; ++j){
            x = (x<<1)|(s[i][j]=='O');
        }
        a[i] = x;
    }

    linear_basis lb;
    for(int i = 0; i < m; ++i){
        lb.insert(a[i]);
    }

    std::cout << (1LL<<lb.count())%2008 << "\n";
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