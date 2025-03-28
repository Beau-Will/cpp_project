// Problem: C - Variety Split Easy
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;std::cin >> n;
	std::vector<int> a(n+2);
	
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<int> pre(n+1),suf(n+2);
	std::set<int> set1,set2;
	for(int i = 1;i<=n;++i){
		set1.insert(a[i]);
		pre[i] = set1.size();
	}
	for(int i = n;i>=1;--i){
		set2.insert(a[i]);
		suf[i] = set2.size();
	}
	
	int ans = 0;
	for(int i = 1;i<=n-1;++i){
		ans = std::max(ans,pre[i]+suf[i+1]);
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