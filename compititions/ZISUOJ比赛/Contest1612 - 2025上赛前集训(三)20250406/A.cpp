#include <bits/stdc++.h>

using i64 = long long;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n+1);
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    int cnt0 = 0,cnt9 = 0;
    for(int i = 1; i <= n; ++i){
        int t = a[i];
        while(t){
            if(t%10==0){
                ++cnt0;
            }else if(t%10==9){
                ++cnt9;
            }
            t/=10;
        }
    }

    std::cout << cnt0 << " " << cnt9 << "\n";

    return 0;
}