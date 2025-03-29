// Problem: A - Thermometer
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

void solve(){
	double t;std::cin >> t;
	
	if(t>=38.0){
		std::cout << 1 << "\n";
	}else if(t>=37.5){
		std::cout << 2 << "\n";
	}else{
		std::cout << 3 << "\n";
	}
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