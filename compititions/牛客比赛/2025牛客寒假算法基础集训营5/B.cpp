// Problem: 小L出师了
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95337/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,t,k;std::cin >> n >> t >> k;
	std::cout << std::min((n-k)/t,k+1) << "\n";
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