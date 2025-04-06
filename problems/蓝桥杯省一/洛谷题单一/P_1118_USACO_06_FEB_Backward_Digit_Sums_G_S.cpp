#include <bits/stdc++.h>

using i64 = long long;

void solve(){
    int n,sum;
    std::cin >> n >> sum;

    std::vector<int> a(n);
    std::iota(a.begin(),a.end(),1);

    std::vector<int> fac(13);
    fac[0] = 1;
    for(int i = 1; i < 13; ++i){
        fac[i]=fac[i-1]*i;
    }
    auto C = [&](int a,int b){
        return fac[a]/(fac[a-b]*fac[b]);
    };

    std::vector<int> k(n);
    for(int i = 0; i < n; ++i){
        k[i] = C(n-1,i);
    }

    do{
        int t = 0;
        for(int i = 0; i < n; ++i){
            t += k[i]*a[i];
        }
        if(t==sum){
            for(int i = 0; i < n; ++i){
                std::cout << a[i] << " \n"[i+1==n];
            }
            return;
        }
    }while(std::next_permutation(a.begin(),a.end()));
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