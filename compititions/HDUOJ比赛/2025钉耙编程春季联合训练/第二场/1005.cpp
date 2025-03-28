// Problem: 学几何导致的
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1151&pid=1005
// Memory Limit: 65536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	i64 n,k;
	std::cin >> n >> k;
	if(k%2==1){
		std::cout << 0 << "\n";
		return;
	}
	i64 t = k/2-1;
	if(n<=k/2){
		std::cout << 0 << "\n";
		return;
	}
	n-=t+1;
	
	i64 d = n/k;
	i64 r = n%k;
	
	i64 ans = (1+d)*d/2*k;
	
	ans += r*((n+k-1)/k);
	
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