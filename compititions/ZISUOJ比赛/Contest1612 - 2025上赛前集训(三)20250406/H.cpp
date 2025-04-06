#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for(int i = 1; i < n; ++i){
        std::cin >> b[i];
    }

    std::vector<int> a(n+1);

    auto check = [&](int x){
        std::set<int> set;
        set.insert(x);//x = a[1]
        for(int i = 1; i < n; ++i){
            x ^= b[i];//x = a[i+1]
            if(set.count(x)){
                return false;
            }
            if(x<0||x>=n){
                return false;
            }
            set.insert(x);
        }
        return true;
    };

    for(int i = 0; i < n; ++i){
        // std::cout << "i:" << i << "\n";
        //枚举a[1]
        if(check(i)){
            // std::cout << i << "isok!\n";
            int t = i;
            std::cout << t << " ";
            for(int j = 1; j < n; ++j){
                t ^= b[j];
                std::cout << t << " \n"[j+1==n];
            }
            return;
        }
    }
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