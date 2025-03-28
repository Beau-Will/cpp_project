// Problem: C. Trip to the Olympiad
// Contest: Codeforces - Hello 2025
// URL: https://codeforces.com/contest/2057/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int l,r;std::cin >> l >> r;
	int a = 0,b = 0,c = l;
	for(int i = 29;i>=0;--i){
		if((l^r)>>i&1){
			a |= (1<<i)-1;
			b |= 1<<i;
			break;
		}else{
			a |= l&(1<<i);
			b |= l&(1<<i);
		}
	}
	while(c==a||c==b) ++c;
	std::cout << a << ' ' << b << ' ' << c << '\n';
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