#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 5e4+5;
std::vector<int> a(N,0),pre(N,0);
int n,k;
bool check(int x) {
    int cnt = 0,sum = 0;
    
    for(int i = 1;i<=n;++i) {
        if(sum+a[i]<=x) sum+=a[i];
        else sum=a[i],++cnt;
    }
    if(sum>0) ++cnt;
    
    return cnt<=k;
}
int biSearch(int l,int r) {
    int ans = 0x3f3f3f3f;
    while(l<=r) {
        int mid = (l+r)>>1;

        if(check(mid)) {
            r = mid-1;
            ans = std::min(ans,mid);
        }else {
            l = mid+1;
        }
    }
    return ans;
}
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
 
    std::cin >> n >> k;
    int max = -1;
    for(int i = 1;i<=n;++i) {
        std::cin >> a[i];
        pre[i] = pre[i-1]+a[i];
        max = std::max(max,a[i]);
    }
    std::cout << biSearch(max,pre[n]) << '\n';
     
    return 0;
}