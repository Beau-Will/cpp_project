// Problem: A - Odd Queries
// Contest: Virtual Judge - 25上ACM综合训练(一)
// URL: https://vjudge.net/contest/704285#problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,q;
	std::cin >> n >> q;
	
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<i64> pre(n+1);
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i-1]+a[i];
	}
	
	while(q--){
		int l,r,k;
		std::cin >> l >> r >> k;
		
		std::cout << ((pre[l-1]+pre[n]-pre[r]+1LL*k*(r-l+1))%2?"YES":"NO") << "\n";
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