#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,k;
    std::cin >> n >> k;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    auto med = [&](const std::set<int> &set){
        for(int i = 0; i <= set.size(); ++i){
            if(set.count(i)){
                continue;
            }
            return i;
        }
    };
    auto check = [&](int x){
        int tmpk = k;
        std::set<int> st;
        int lastv = 0,lastsz = 0;
        for(int i = 1; i <= n; ++i){
            st.insert(a[i]);
            int v;
            if(st.size()!=lastsz){
                v = med(st);
            }else{
                v = lastv;
            }
            lastv = v;
            lastsz = st.size();
            if(v>=x){
                --tmpk;
                st.clear();
                lastv = 0;
                lastsz = 0;
            }
            if(tmpk > n-i+1){
                return false;
            }
            if(tmpk == 0){
                return true;
            }
        }
        return tmpk == 0;
    };
    // std::set<int> init;
    // for(int i = 0; i <= n+1; ++i){
    //     init.insert(i);
    // }
    // auto check = [&](int x){
        
    //     auto set = init;
    //     int tmpk = k;
    //     for(int i = 1; i <= n; ++i){
    //         int ai = a[i]>=n?n:a[i];
    //         if(set.count(a[i])){
    //             set.erase(a[i]);
    //         }
    //         int med = *set.begin();
    //         if(med>=x){
    //             --tmpk;
    //             set = init;//TLE在这
    //         }
    //         if(tmpk > n-i+1){
    //             return false;
    //         }
    //         if(tmpk==0){
    //             break;
    //         }
    //     }
    //     return tmpk == 0;
    // };

    int lo = 0,hi = n;
    while(lo < hi){
        int mid = (lo+hi+1)>>1;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }

    std::cout << lo << "\n";
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