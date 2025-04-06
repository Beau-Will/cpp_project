#include <bits/stdc++.h>

using i64 = long long;

struct Node{
    int t,d,l;
    bool operator < (const Node &t2) const{
        if(t+d!=t2.t+t2.d){
            return t+d < t2.t+t2.d;
        }
        return l < t2.l;
    }
};

void solve(){
    int n;
    std::cin >> n;

    std::vector<Node> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i].t >> a[i].d >> a[i].l;
    }

    std::vector<int> b(n);
    std::iota(b.begin(),b.end(),0);
    bool isok = false;
    do{
        int cur = 0;
        bool flag = true;
        for(int i = 0; i < n; ++i){
            int id = b[i];
            if(cur > a[id].t+a[id].d){
                flag = false;
                break;
            }
            cur = std::max(cur,a[id].t);
            cur += a[id].l;
        }
        if(flag){
            isok = true;
            break;
        }
    }while(std::next_permutation(b.begin(),b.end()));

    std::cout << (isok?"YES\n":"NO\n");
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