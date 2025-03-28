// Problem: 猪猪养成计划2
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/99785/D
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	
	std::vector<int> a(n+1);
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> b(n+1),val(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> b[i] >> val[i];
	}
	
	std::vector<int> 
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