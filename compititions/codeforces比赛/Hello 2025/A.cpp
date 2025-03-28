// Problem: A. MEX Table
// Contest: Codeforces - Hello 2025
// URL: https://codeforces.com/contest/2057/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

int main(){
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	int t = 1;
	std::cin >> t;
	for(int ti = 0;ti<t;++ti){
		int n,m;std::cin >> n >> m;
		std::cout << (std::max(n,m)+1) << '\n';
	}
	
	return 0;
}