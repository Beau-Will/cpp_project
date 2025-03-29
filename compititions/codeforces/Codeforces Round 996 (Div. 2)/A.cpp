// Problem: A. Two Frogs
// Contest: Codeforces - Codeforces Round 996 (Div. 2)
// URL: https://codeforces.com/contest/2055/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,a,b;std::cin >> n >> a >> b;
	std::cout << (std::abs(b-a)&1?"NO":"YES") << '\n';
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