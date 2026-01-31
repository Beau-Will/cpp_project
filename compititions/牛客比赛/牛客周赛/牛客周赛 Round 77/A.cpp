// Problem: 时间表
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/100253/A
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	std::vector<int> ans = {20250121,20250123,20250126,20250206,20250208,20250211};
	int n;std::cin >> n;
	std::cout << ans[n-1] << '\n';
}

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	//std::cin >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}