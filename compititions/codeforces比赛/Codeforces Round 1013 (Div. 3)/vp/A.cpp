// Problem: A. Olympiad Date
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/contest/2091/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using i64 = long long;

//2025.03.01
/*
	0:3
	1:1
	2:2
	3:1
	5:1
*/

void solve(){
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::vector<int> cnt(10);
	
	auto check = [&](){
		if(cnt[0]<3){
			return false;
		}
		if(cnt[1]<1){
			return false;
		}
		if(cnt[2]<2){
			return false;
		}
		if(cnt[3]<1){
			return false;
		}
		if(cnt[5]<1){
			return false;
		}
		return true;
	};
	
	for(int i = 0; i < n; ++i){
		++cnt[a[i]];
		if(check()){
			std::cout << i+1 << "\n";
			return;
		}
	}
	
	std::cout << "0\n";
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