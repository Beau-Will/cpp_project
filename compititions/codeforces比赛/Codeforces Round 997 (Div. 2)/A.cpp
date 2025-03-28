// Problem: A. Shape Perimeter
// Contest: Codeforces - Codeforces Round 997 (Div. 2)
// URL: https://codeforces.com/contest/2056/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m;std::cin >> n >> m;
	i64 ans = 4*m;
	int lastx = -1,lasty = -1;
	for(int i = 0;i<n;++i){
		int x,y;std::cin >> x >> y;
		if(i>0){
			ans += 4*m-2*((m-x)+(m-y));
		}
		lastx = x,lasty = y;
	}
	std::cout << ans << '\n';
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