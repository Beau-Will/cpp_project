// Problem: 小苯的线性dp
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1'000'000'000;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<i64> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<i64> pre_sum(n+1);
	for(int i = 1; i <= n; ++i){
		pre_sum[i] = pre_sum[i-1]+a[i-1];
	}
	
	std::vector<i64> ans(n+1);
	for(int i = 1; i <= n-2; ++i){
		//枚举区间总长度
		std::vector<i64> pre(n+1),suf(n+2);
        for(int j = 1; j <= n; ++j){
            pre[j] = std::max(pre[j-1],pre_sum[j]-pre_sum[std::max(0,j-i)]);
        }
        for(int j = n; j >= 1; --j){
            suf[j] = std::max(suf[j+1],pre_sum[std::min(n,j+i-1)]-pre_sum[j-1]);
        }
        for(int j = 1; j <= n; ++j){
            ans[i] = std::max(ans[i],std::max(pre[j-1],suf[j+1])-a[j-1]);
        }
	}
	
    ans[n-1] = std::max(pre_sum[n]-a[0]-a[0],pre_sum[n-1]-a[n-1]);
    
	for(int i = 1; i <= n; ++i){
		std::cout << ans[i] << " \n"[i==n];
	}
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