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
	
	std::vector<int> a(n),b(m);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	for(int i = 0; i < m; ++i){
		std::cin >> b[i];
	}
	
	std::sort(a.rbegin(),a.rend());
	std::sort(b.rbegin(),b.rend());
	
	std::vector<i64> prea(n+1),preb(m+1);
	for(int i = 0; i < n; ++i){
		prea[i+1] = prea[i]+a[i];
	}
	for(int i = 0; i < m; ++i){
		preb[i+1] = preb[i]+b[i];
	}
	
	int cnta = 0,cntb = 0;
	for(int i = 0; i < n; ++i){
		if(a[i]>=0){
			++cnta;
		}
	}
	for(int i = 0; i < m; ++i){
		if(b[i]>=0){
			++cntb;
		}
	}
	
	if(cnta>=cntb){
		std::cout << prea[cnta]+preb[cntb] << "\n";
	}else{
		i64 ans = 0;
		for(int i = 1; i <= std::min(n,m); ++i){
			ans = std::max(ans,prea[i]+preb[i]);
			ans = std::max(ans,prea[i]+preb[i-1]);
		}
		std::cout << ans << "\n";
	}
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