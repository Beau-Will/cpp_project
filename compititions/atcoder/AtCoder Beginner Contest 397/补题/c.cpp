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
	
	std::vector<int> a(n+1);
	for(int i = 1;i<=n;++i){
		std::cin >> a[i];
	}
	
	std::vector<bool> vis1(n+1),vis2(n+1);
	std::vector<int> pre(n+1),suf(n+2);
	
	for(int i = 1;i<=n;++i){
		if(!vis1[a[i]]){
			pre[i] = pre[i-1]+1;
			vis1[a[i]] = true;
		}else{
			pre[i] = pre[i-1];
		}
	}
	for(int i = n;i>=1;--i){
		if(!vis2[a[i]]){
			suf[i] = suf[i+1]+1;
			vis2[a[i]] = true;
		}else{
			suf[i] = suf[i+1];
		}
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