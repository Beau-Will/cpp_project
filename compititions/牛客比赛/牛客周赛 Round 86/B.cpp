// Problem: 小苯的区间删除
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/104637/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,k;
	std::cin >> n >> k;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	for(int i = 0; i < n; ++i){
		if(a[i]>=0){
			ans += a[i];
		}
	}
	
	std::cout << ans << "\n";
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}