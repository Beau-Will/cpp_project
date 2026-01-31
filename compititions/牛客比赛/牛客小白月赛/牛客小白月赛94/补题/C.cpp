// Problem: 小苯的数字合并
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/82957/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<i64> pre(n+1);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1]+a[i];
	}
	
	i64 ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = std::max(ans,pre[i]-a[i]-a[i]);
		ans = std::max(ans,pre[n]-pre[i]-a[i]);
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}