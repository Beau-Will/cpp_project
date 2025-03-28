// Problem: C. Combination Lock
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	int n;
	std::cin >> n;
	
	if(n%2==0){
		std::cout << "-1\n";
		return;
	}
	
	std::vector<int> a(n);
	int t = 1;
	for(int i = 0; i < (n+1)/2; ++i){
		a[i] = t;
		t+=2;
	}
	t = 2;
	for(int i = (n+1)/2; i < n; ++i){
		a[i] = t;
		t += 2;
	}
	
	for(int i = 0; i < n; ++i){
		std::cout << a[i] << " \n"[i+1==n];
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