#include <bits/stdc++.h>

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    int n,t;std::cin >> n >> t;
    
    std::vector<int> a(n+1),pre(n+1);
    for(int i = 1;i<=n;++i){
        std::cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }

    int idx = std::upper_bound(pre.begin(),pre.end(),t)-pre.begin();
    std::cout << idx-1 << '\n';
    
    return 0;
}