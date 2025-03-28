#include <bits/stdc++.h>

using i64 = long long;

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;i64 t;std::cin >> n >> t;
    
    std::vector<int> a(n+1);
    for(int i = 1;i<=n;++i){
        std::cin >> a[i];
    }
    
    int ans = 0;
    i64 sum = 0;
    for(int i = 1,j = 1;i<=n&&j<=n;++i){
        while(j<=n&&sum<=t){
            if(sum+a[j]>t) break;
            sum+=a[j];
            ++j;
        }
        ans = std::max(ans,j-i);
        sum-=a[i];
    }
    std::cout << ans << '\n';
    
    return 0;
}