// Problem: C - Buy Balls
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;
	std::cin >> n >> m;
	
	std::vector<int> a(n+1),b(m+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	for(int i = 1; i <= m; ++i){
		std::cin >> b[i];
	}
	
	std::sort(a.begin()+1,a.end(),std::greater<int>());
	std::sort(b.begin()+1,b.end(),std::greater<int>());
	
	
	std::vector<i64> prea(n+1),preb(m+1);
	for(int i = 1; i <= n; ++i){
		prea[i] = prea[i-1]+a[i];
	}
	for(int i = 1; i <= m; ++i){
		preb[i] = preb[i-1]+b[i];
	}

	i64 ans = 0;
	for(int i = 0; i <= std::min(n,m); ++i){
		int idx = std::upper_bound(a.begin()+i+1,a.end(),0,std::greater<int>())-a.begin();
		--idx;
		ans = std::max(ans,preb[i]+prea[idx]);
	}
	
	std::cout << ans << "\n";
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