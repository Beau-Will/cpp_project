// Problem: D. Place of the Olympiad
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n,m,k;
	std::cin >> n >> m >> k;
	
	int t = (k+n-1)/n;
	
	int lo = 1,hi = m;
	while(lo < hi){
		int mid = (lo + hi)>>1;
		int tmp = (t+mid-1)/mid -1 + t;
		if(tmp <= m){
			hi = mid;
		}else{
			lo = mid+1;
		}
	}
	
	std::cout << lo << "\n";
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